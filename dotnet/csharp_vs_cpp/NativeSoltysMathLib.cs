using System.Runtime.InteropServices;

namespace csharp_vs_cpp;

public class NativeSoltysMathLib
{
    [DllImport("soltys_math_lib.dll")]
    public static extern int sm_is_prime(long n);
}