import java.util.*;

public class largest {
    public static void main(String args[]) {
        System.out.println( "Enter three numbers : ");

        //taking i/p
        Scanner sc = new Scanner(System.in);
        Scanner sc1 = new Scanner(System.in);
        Scanner sc2 = new Scanner(System.in);


        int a = sc.nextInt();
        int b = sc1.nextInt();
        int c = sc2.nextInt();
        if (a > b && a > c) {
            System.out.println(a + " is the largest number");
        } else if (b > a && b > c) {
            System.out.println(b + " is the largest number");
        } else {
            System.out.println(c + " is the largest number");
        }
    }
}
