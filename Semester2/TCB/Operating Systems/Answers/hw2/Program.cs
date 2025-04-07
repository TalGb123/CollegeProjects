using System.Diagnostics;

const string FilePath = @"D:\file.bin";
FileCreateAndFillRandom(FilePath);
CalculateSumSingleThreaded(FilePath);
//Milliseconds Elapsed: 2666
//Result: 136905427457
long globalSum = 0;
MultiThreadHandling(FilePath);
//Multithreaded Sum: 136905427457
//Milliseconds Elapsed(3 threads): 1093

void FileCreateAndFillRandom(string filePath)
{
    FileStream fs = File.Create(filePath);
    Random rnd = new Random();
    byte[] b = new byte[(int)Math.Pow(2, 30)]; 
    rnd.NextBytes(b);
    fs.Write(b, 0, b.Length); 
    fs.Close(); 
}

void CalculateSumSingleThreaded(string filePath)
{
    FileCreateAndFillRandom(filePath);
    Stopwatch sw = Stopwatch.StartNew();
    byte[] buff = File.ReadAllBytes(filePath);
    long sum = 0;
    foreach (byte b in buff)
    {
        sum += b;
    }
    sw.Stop();
    Console.WriteLine($"Milliseconds Elapsed: {sw.ElapsedMilliseconds}");
    Console.WriteLine($"Result: {sum}");
}


void MultiThreadHandling(string filePath)
{
    const int _1GiB = 1 << 30;
    Thread t1 = new(CalculateSumMultiThreaded),
        t2 = new(CalculateSumMultiThreaded),
        t3 = new(CalculateSumMultiThreaded);
    var parameters = new List<Parameter>
    {
        new() { FilePath = filePath, Start = 0, End = _1GiB / 3 },
        new() { FilePath = filePath, Start = _1GiB / 3, End = (_1GiB / 3) * 2 },
        new() { FilePath = filePath, Start = (_1GiB / 3) * 2, End = _1GiB }
    };
    var sw = Stopwatch.StartNew();
    t1.Start(parameters[0]); t2.Start(parameters[1]); t3.Start(parameters[2]);
    t1.Join(); t2.Join(); t3.Join();
    sw.Stop();
    Console.WriteLine($"Multithreaded Sum: {globalSum}");
    Console.WriteLine($"Milliseconds Elapsed (3 threads): {sw.ElapsedMilliseconds}");
}

void CalculateSumMultiThreaded(object obj)
{
    Parameter p = (Parameter)obj;

    using FileStream fs = new FileStream(p.FilePath, FileMode.Open, FileAccess.Read);
    fs.Seek(p.Start, SeekOrigin.Begin);
    int length = p.End - p.Start;
    byte[] buffer = new byte[length];
    fs.Read(buffer, 0, length);

    long localSum = 0;
    foreach (byte b in buffer)
    {
        localSum += b;
    }
    Interlocked.Add(ref globalSum, localSum);
}

class Parameter
{
    public string FilePath { get; set; }
    public int Start { get; set; }
    public int End { get; set; }
}
