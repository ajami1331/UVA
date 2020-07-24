import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static BufferedReader in;
    public static PrintWriter out;
    public static StringTokenizer tok;
        
    public static void main(String args[]) throws IOException {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
            //in = new BufferedReader(new FileReader("in.txt"));
            //out = new PrintWriter(new FileWriter("out.txt"));
            solve();
            in.close();
            out.close();
    }
    
    static void solve() throws IOException {
        BigInteger[] fib = new BigInteger[5001];
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        for (int i=2; i<=5000; i++) {
            fib[i] = fib[i-1].add(fib[i-2]);
        }
        int n;
        while ( hasNext() ) {
            n = nextInt();
            out.printf("The Fibonacci number for %d is ", n);
            out.println(fib[n]);
        }
    }
    
    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static BigInteger nextBigInteger() throws IOException {
        return new BigInteger(next());
    }
    
    public static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }
    
    public static String nextLine() throws IOException {
        tok = new StringTokenizer("");
        return in.readLine();
    }

    public static boolean hasNext() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return false;
            }
            tok = new StringTokenizer(s);
        }
        return true;
    }
    
}