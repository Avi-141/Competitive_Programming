import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
        CodeEatSwitcher solver = new CodeEatSwitcher();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CodeEatSwitcher {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int q = sc.nextInt();
            int n = sc.nextInt();

            double coding = 0;
            double eating = 0;

            Slot s[] = new Slot[n];
            for (int i = 0; i < n; ++i) {
                s[i] = new Slot(sc.nextLong(), sc.nextLong());
                coding += s[i].c;
            }

            Arrays.sort(s, new Comparator<Slot>() {

                public int compare(Slot o1, Slot o2) {
                    if (o1.c * o2.e < o2.c * o1.e)
                        return -1;
                    if (o1.c * o2.e > o2.c * o1.e)
                        return 1;
                    return 0;
                }
            });

            Query query[] = new Query[q];
            for (int i = 0; i < q; ++i) {
                query[i] = new Query(i, sc.nextLong(), sc.nextLong());
            }

            Arrays.sort(query, new Comparator<Query>() {

                public int compare(Query o1, Query o2) {
                    if (o1.b < o2.b)
                        return -1;
                    if (o1.b > o2.b)
                        return 1;
                    return 0;
                }
            });

            int nextInd = 0;
            char ans[] = new char[q];
            for (int i = 0; i < q; ++i) {
                while (nextInd < n && eating + s[nextInd].e <= query[i].b) {
                    eating += s[nextInd].e;
                    coding -= s[nextInd].c;
                    nextInd++;
                }

                double curEating = eating;
                double curCoding = coding;

                if (curEating <= query[i].b && nextInd < n) {
                    double req = query[i].b - curEating;
                    curCoding -= req * s[nextInd].c / s[nextInd].e;
                    curEating += req;
                }

                if (curCoding >= query[i].a && curEating >= query[i].b) {
                    ans[query[i].ind] = 'Y';
                } else
                    ans[query[i].ind] = 'N';
            }

            out.print("Case #" + testNumber + ": ");
            for (int i = 0; i < q; ++i)
                out.print(ans[i]);
            out.println();
        }

        class Query {
            int ind;
            double a;
            double b;

            Query(int ind, double a, double b) {
                this.ind = ind;
                this.a = a;
                this.b = b;
            }

        }

        class Slot {
            double c;
            double e;

            Slot(double a, double b) {
                c = a;
                e = b;
            }

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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;

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

