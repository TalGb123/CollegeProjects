using System.Diagnostics;

string subnet = "216.58.214";
Parallel.For(0, 256, (i) =>
{
    string ip = $"{subnet}.{i}";
    PingIP(ip);
});

static void PingIP(string ip)
{
    ProcessStartInfo psi = new ProcessStartInfo
    {
        FileName = "ping",
        Arguments = $"-n 1 -w 200 {ip}",
        RedirectStandardOutput = true,
        UseShellExecute = false,
        CreateNoWindow = true
    };
    using (Process process = Process.Start(psi))
    {
        string output = process.StandardOutput.ReadToEnd();
        process.WaitForExit();
        if (process.ExitCode == 0)
            Console.WriteLine($"{ip} is ONLINE");
        else
            Console.WriteLine($"{ip} is OFFLINE");
    }
}