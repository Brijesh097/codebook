import java.math.BigInteger;
import java.util.Scanner;
 
public class Main
{
    static BigInteger factorial(int N)
    {
        BigInteger f = new BigInteger("1");
        for (int i = 2; i <= N; i++)
            f = f.multiply(BigInteger.valueOf(i));
        return f;
    }
    public static void main(String args[]) throws Exception
    {
        int N = 20;
        System.out.println(factorial(N));
    }
}

// Operations
String str = "123456789";
BigInteger C = A.add(new BigInteger(str));
int val  = 123456789;
BigInteger C = A.add(BigIntger.valueOf(val)); 

// Extraction
int x   =  A.intValue();
long y   = A.longValue();
String z = A.toString();  

// Comparison
if (a < b) {}  // Integer
if (A.compareTo(B) < 0)  {} // BigInteger
if (A.equals(B)) {}