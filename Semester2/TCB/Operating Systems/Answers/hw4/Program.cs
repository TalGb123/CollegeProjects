using System;
using System.Threading;
using System.Timers;

class Program
{
      static readonly object consoleLock = new();
      static readonly SemaphoreSlim stationSlots = new(10);
      static readonly Random rnd = new();
      static int totalFuel = 120000; 
      static readonly object fuelLock = new();
      static CancellationTokenSource cts = new();
      static int vehicleCount = 0;
      static bool fuelDepleted = false;

      static void Main()
      {
            System.Timers.Timer gasStationTimeoutTimer = new();
            gasStationTimeoutTimer.Interval = 5000; 
            gasStationTimeoutTimer.Elapsed += GasStationTimeoutTimerElapsed;
            gasStationTimeoutTimer.AutoReset = false;
            gasStationTimeoutTimer.Start();

            System.Timers.Timer vehicleCreationTimer = new();
            vehicleCreationTimer.Interval = rnd.Next(5, 25); 
            vehicleCreationTimer.Elapsed += VehiclesCreationTimerElapsed;
            vehicleCreationTimer.AutoReset = true;
            vehicleCreationTimer.Start();

            Console.ReadLine(); 
      }

      static void GasStationTimeoutTimerElapsed(object? sender, ElapsedEventArgs e)
      {
            PrintWithLock("Gas station closing timeout of 5000 elapsed");
            cts.Cancel();
      }

      static void FuelDepleted()
      {
            if (!fuelDepleted)
            {
                  fuelDepleted = true;
                  cts.Cancel();
                  PrintWithLock("Gas station closing: Fuel depleted");
            }
      }

      static void VehiclesCreationTimerElapsed(object? sender, ElapsedEventArgs e)
      {
            if (cts.IsCancellationRequested) return;

            Thread t = new(new ParameterizedThreadStart(VehicleProc));
            Vehicle v = new(cts.Token);
            PrintWithLock($"Vehicle {v.Id} created");
            t.Start(v);
      }

      static void VehicleProc(object? obj)
      {
            Vehicle v = (Vehicle)obj!;
            try
            {
                  stationSlots.Wait(v.CancellationToken);
            }
            catch
            {
                  PrintWithLock($"Vehicle {v.Id} received cancellation request while waiting to enter the gas station");
                  return;
            }

            if (cts.IsCancellationRequested || v.CancellationToken.IsCancellationRequested)
            {
                  stationSlots.Release();
                  PrintWithLock($"Vehicle {v.Id} received cancellation request while waiting to enter the gas station");
                  return;
            }

            PrintWithLock($"Vehicle {v.Id} entered the gas station");

            int fuelNeeded;
            lock (fuelLock)
            {
                  if (totalFuel <= 0)
                  {
                  stationSlots.Release();
                  PrintWithLock($"Vehicle {v.Id} leaved the gas station");
                  return;
                  }

                  fuelNeeded = rnd.Next(111, 151); 
                  if (fuelNeeded > totalFuel)
                  fuelNeeded = totalFuel;

                  totalFuel -= fuelNeeded;
            }

            Thread.Sleep(rnd.Next(100, 300)); 
            PrintWithLock($"Vehicle {v.Id} fueled {fuelNeeded}");
            PrintWithLock($"Total fuel: {totalFuel}");

            if (totalFuel == 0)
                  FuelDepleted();

            PrintWithLock($"Vehicle {v.Id} leaved the gas station");
            stationSlots.Release();
      }

      static void PrintWithLock(string str)
      {
            lock (consoleLock)
            {
                  Console.WriteLine(str);
            }
      }
}
