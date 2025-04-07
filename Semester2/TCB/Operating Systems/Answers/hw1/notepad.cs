using System.Diagnostics;

NPOpener();
static void NPOpener()
{
    ProcessStartInfo psi = new ProcessStartInfo
    {
        FileName = "notepad.exe",
        Arguments = "1.txt",
        UseShellExecute = false
    };

    Process process = Process.Start(psi);
    Console.WriteLine($"Notepad started with PID: {process.Id}");

    Thread.Sleep(5000); // Wait for 5 seconds

    if (!process.HasExited){
        process.Kill();
        process.WaitForExit();
        Console.WriteLine($"Notepad terminated. Exit code: {process.ExitCode}");
    }
    else{
        Console.WriteLine("Notepad was closed manually before termination.");
    }
}