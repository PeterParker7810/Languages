import java.util.Scanner;

public class Char_Counter{

    public static void Count(StringBuilder str, int[] ar){
        for (int i = 0; i < ar.length; i++){
            int count = 0;
            for (int j = 0; j < ar.length; j++){
                if (str.charAt(i) == str.charAt(j)){
                    count++;
                }
            }
            ar[i] = count;
        }
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the String: ");
        StringBuilder user = new StringBuilder(input.nextLine());

        int[] count = new int[user.length()];

        Count(user,count);

        StringBuilder out = new StringBuilder();
        for (int i = 0; i < user.length(); i++){
            int check = 0;
            for (int j = 0; j < user.length(); j++){
                if (user.charAt(i) == user.charAt(j) && check == 0 && out.indexOf(String.valueOf(user.charAt(i))) == -1){
                    out.append(user.charAt(i));
                    check++;
                }
            }
        }

        System.out.print("Output String: ");
        int[] count2 = new int[out.length()];
        for (int i = 0; i < out.length(); i++){
            int index = user.indexOf(String.valueOf(out.charAt(i)));
            count2[i] = count[index];
            System.out.print(count2[i] + String.valueOf(out.charAt(i)));
        }
    }
}