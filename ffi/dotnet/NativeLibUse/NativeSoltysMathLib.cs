using System.Runtime.InteropServices;

namespace NativeLibUse;

public class NativeSoltysMathLib
{
    [DllImport("soltys_math_lib.dll")]
    public static extern int sm_is_prime(long n);
}