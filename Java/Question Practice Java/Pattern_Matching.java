import java.util.Scanner;

public class Pattern_Matching{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the String: ");
        String str = input.nextLine();
        
        System.out.print("Enter the Pattern: ");
        StringBuilder pattern = new StringBuilder(input.nextLine());

        int start = 0;

        StringBuilder temp = new StringBuilder();

        for (int i = 0; i < pattern.length(); i++){
            if (pattern.charAt(i) == '.'){
                temp.append(pattern.charAt(i+1));
                start = i+1;
            }
            else{
                temp.append(pattern.charAt(i));
            }
        }

        if (pattern.indexOf("*") < pattern.length()){
            pattern = new StringBuilder(temp.substring(0, temp.indexOf("*")));
            
            temp = new StringBuilder(pattern.substring(start, pattern.length()));
    
            for (int i = 0; i < str.length(); i++){
                pattern.append(temp);
            }
        }

        pattern = new StringBuilder(pattern.substring(0, str.length()));
        if (str.equals(pattern)){
            System.out.println("Yess....String Matches the Pattern");
        }
        else{
            System.out.println("Noo....String does not Matches the Pattern");
        }
    }
}