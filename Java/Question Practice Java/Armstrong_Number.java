import java.util.Scanner;

public class Armstrong_Number{
    public static void main(String[] args){
        try (Scanner scanner = new Scanner(System.in)) {
            System.err.print("Enter the number: ");
            int num = scanner.nextInt();

            int power = 0;
            int check = num;

            while (num != 0){
                num /= 10;
                power++;
            }

            int check1 = check;
            int sum = 0;
            while (check != 0){
                double value = Math.pow(check%10,power);
                sum += value;
                check /= 10;
            }

            if (check1 == sum){
                System.out.print("Yes..");
                System.out.print(check1);
                System.out.print(" is an Armstrong Number");
            }
            else{
                System.out.print("No..");
                System.out.print(check1);
                System.out.print(" is not an Armstrong Number");
            }
        }
    }
}