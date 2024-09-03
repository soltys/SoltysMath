using BenchmarkDotNet.Attributes;

namespace csharp_vs_cpp;

public class Benchmark
{
    [Benchmark]
    public void Native()
    {
        for (long i = 1_000_000_000_000_000; i <= 1_000_000_000_000_100; i++)
        {
            NativeSoltysMathLib.sm_is_prime(i);
        }
    }

    [Benchmark]
    public void DotNet()
    {

        for (long i = 1_000_000_000_000_000; i <= 1_000_000_000_000_100; i++)
        {
            DotnetSoltysMathLib.IsPrime(i);
        }
    }

}