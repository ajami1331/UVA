import java.io.*;
import java.util.*;
import java.math.*;
import java.math.BigInteger;

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
        BigInteger a, b;
        
        while(hasNext()) {
            a = nextBigInteger();  b = nextBigInteger();
            a = a.multiply(b);
            out.println(a);
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