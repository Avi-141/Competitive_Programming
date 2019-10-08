import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Solution {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        StreetCheckers solver = new StreetCheckers();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class StreetCheckers {
        HashSet<Integer> primes;
        boolean preComputed = false;

        int countPrimes(int l, int r) {
            if (r < l)
                return 0;

            int size = r - l + 1;
            int sieve[] = new int[size];
            for (int i = 2; i <= 100000; ++i) {
                int minVal = ((l - 1) / i + 1) * i;
                for (int j = minVal; j <= r; j += i) {
                    sieve[j - l] = i;
                }
            }

            if (l == 1)
                sieve[0] = -1;

            int cnt = 0;
            for (int i = l; i <= r; ++i) {
                if (sieve[i - l] == 0 || primes.contains(i))
                    cnt++;
            }

            return cnt;
        }

        void preCompute() {
            preComputed = true;
            primes = new HashSet<>();
            int sieve[] = new int[100001];
            for (int i = 2; i <= 100000; ++i) {
                if (sieve[i] == 0) {
                    if (i != 2)
                        primes.add(i);
                    for (int j = i; j <= 100000; j += i)
                        sieve[j] = i;
                }
            }
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            if (!preComputed)
                preCompute();

            int l = sc.nextInt();
            int r = sc.nextInt();

            int ans = (r / 2 - r / 4) - ((l - 1) / 2 - (l - 1) / 4);
            if (1 >= l && 1 <= r)
                ans++;
            ans += countPrimes(l, r);
            if (4 >= l && 4 <= r)
                ans++;
            if (8 >= l && 8 <= r)
                ans++;
            int newL = ((l - 1) / 4 + 1);
            int newR = (r / 4);
            ans += countPrimes(newL, newR);
            out.println("Case #" + testNumber + ": " + ans);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));

            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

