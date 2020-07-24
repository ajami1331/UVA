import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
    public BufferedReader in;
    public PrintWriter out;
    public StringTokenizer tok;
        
    public void main(String args[]) throws IOException {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
            //in = new BufferedReader(new FileReader("in.txt"));
            //out = new PrintWriter(new FileWriter("out.txt"));
            solve();
            in.close();
            out.close();
    }
    
    void solve(){
        
    }
    
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public BigInteger nextBigInteger() throws IOException {
        return new BigInteger(next());
    }
    
    public String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }
    
    public String nextLine() throws IOException {
        tok = new StringTokenizer("");
        return in.readLine();
    }

    public boolean hasNext() throws IOException {
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