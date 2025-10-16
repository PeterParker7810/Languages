import java.util.Scanner;
import java.util.Stack;
public class Stack_Functions{
    public static void Push(Stack<Integer> stack, int size, int val) {
        if (stack.size() < size) {
            stack.push(val);
            System.out.println("\nPushed " + val);
        } else System.out.println("\nStack Overflow");
    }

    public static void Pop(Stack<Integer> stack) {
        if (!stack.isEmpty()) {
            int val = stack.pop();
            System.out.println("\nPopped " + val);
        } else System.out.println("\nStack Underflow");
    }

    public static void Display(Stack<Integer> stack) {
        if (!stack.isEmpty()) {
            System.out.println("\nDisplaying Stack Elements:");
            for (int i = 0; i < stack.size(); i++) System.out.print(stack.get(i) + " ");
            System.out.println();
        } else System.out.println("\nStack is Empty");
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Stack <Integer> stack = new Stack<>();
        
        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();

        System.out.println("\nStack Functions:\n1. Push\n2. Pop\n3. isFull\n4. isEmpty\n5. Count\n6. Display");
        while (true){
            System.out.print("\nEnter Stack Function: ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.print("Enter the Element: ");
                int val = input.nextInt();
                Push(stack, size, val);
            } else if (choice == 2) Pop(stack);
            else if (choice == 3) System.out.println(stack.size() == size ? "\nStack is Full" : "\nStack is Not Full");
            else if (choice == 4) System.out.println(stack.isEmpty() ? "\nStack is Empty" : "\nStack is Not Empty");
            else if (choice == 5) System.out.println("\nCount of Elements in Stack: " + stack.size());
            else if (choice == 6) Display(stack);
            else System.out.println("\nInvalid Choice!");
        }
    }
}