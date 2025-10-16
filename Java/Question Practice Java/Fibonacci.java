import java.util.Scanner;
public class file{
    public static int Fibonacci(int lim){
        if (lim <= 1) return lim;
        return Fibonacci(lim - 1) + Fibonacci(lim - 2);
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the Limit: ");
        int limit = input.nextInt();

        System.out.print("Fibonacci Series: ");
        for (int i = 0; i < limit; i++) System.out.print(Fibonacci(i) + " ");
    }
}