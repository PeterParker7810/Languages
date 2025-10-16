import java.util.*;
public class Binary_to_Decimal_and_vice_versa{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the number type (Binary or Decimal): ");
        String ntype = input.nextLine();
    
        if (ntype.equals("binary")){
            System.out.print("Enter the number: ");
            int num = input.nextInt();

            int limit = 0, ans = 0, num1 = num;
            while (num != 0){
                num /= 10;
                limit++;
            }

            for (int i = 0; i < limit; i++){
                ans += Math.pow(2, i)*(num1%10);
                num1 /= 10;
            }

            System.out.print("Number in Decimal is ");
            System.out.print(ans);
        }

        else if (ntype.equals("decimal")){
            System.out.print("Enter the number: ");
            int num = input.nextInt();

            int[] arr = new int[100];
            int index = 0;

            System.out.print("Number in Binary is ");
            while (num != 1){
                arr[index] = num%2;
                num /= 2;
                index++;
                if (num == 1){
                    arr[index] = num;
                }
            }

            for (int i = index; i >= 0; i--){
                System.out.print(arr[i]);
            }
        }

        else{
            System.out.println("Didn't get that....");
        }
    }
}