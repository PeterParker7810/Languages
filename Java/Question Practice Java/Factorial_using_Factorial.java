import java.util.Scanner;

public class Factorial_using_Factorial{
    public static int Factorial(int n){
        if (n == 0 || n == 1) return 1;
        else return  n * Factorial(n - 1);
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the Number: ");
        int num = input.nextInt();

        int fact = Factorial(num);
        System.out.println("Factorial is " + fact);
    }
}