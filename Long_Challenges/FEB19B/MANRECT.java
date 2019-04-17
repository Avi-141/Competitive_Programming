import java.util.*;

class MANRECT {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- != 0) {
            long A, B, C, D, xl, yl, xu, yu,lim=1000000000;
            System.out.println("Q " + 0 + " " + 0);
            A = sc.nextLong();
            System.out.println("Q " + 0 + " " + lim);
            B = sc.nextLong();
            //System.out.println(t);
            System.out.println("Q " + lim + " " + lim);
            C = sc.nextLong();
            long saveC=C;
            System.out.println("Q " + lim + " " + 0);
            D = sc.nextLong();
            B = lim - B;
            long temp = (A + B) / 2;
            System.out.println("Q " + 0 + " " + temp);
            xl = sc.nextLong();
            yl = A - xl;
            C = lim - C;
            temp = (C + D) / 2;
            System.out.println("Q " + lim + " " + temp);
            xu = lim - sc.nextLong();
            yu = 2*lim-xu-saveC;
            System.out.println("A " + xl + " " + yl + " " + xu + " " + yu);
            int op = sc.nextInt();
            if (op == -1)
                System.exit(0);
        }
    }
}