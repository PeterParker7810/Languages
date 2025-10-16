#include<iostream>
#include<vector>
using namespace std;

void Push(vector <int> &vec, int elem, int size){
    if (vec.size() < size){
        vec.push_back(elem);
        cout<<"\nPushing "<<elem<<" to Stack"<<endl;
    } else cout<<"\nStack Overflow"<<endl;
}

void Pop(vector <int> &vec){
    if (vec.empty()) cout<<"\nStack Underflow"<<endl;
    else{
        cout<<"\nPopped out "<<vec.back()<<endl;
        vec.pop_back();
    }
}

void Display(vector <int> vec){
    cout<<"\nDisplaying Stack Elements:"<<endl;
    for (int i = 0; i < vec.size(); i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int main(){
    vector <int> stack;
    int size;
    cout<<"Enter the size of Stack: ";
    cin>>size;

    cout<<"\nStack Functions\n1. push\n2. pop\n3. isFull\n4. isEmpty\n5. peek\n6. count\n7. display"<<endl;
    while (1){
        int choice;
        cout<<"\nEnter Stack Function: ";
        cin>>choice;

        if (choice == 1){
            int elem;
            cout<<"Enter the Element: ";
            cin>>elem;
            Push(stack, elem, size);
        } else if (choice == 2) Pop(stack);
        else if (choice == 3) cout<<(stack.size() < size ? "\nStack is not Full" : "\nStack is FUll")<<endl;
        else if (choice == 4) cout<<(stack.empty() ? "\nStack is Empty" : "\nStack is not Empty")<<endl;
        else if (choice == 5){
            if (stack.empty()) cout<<"\nPeeking ";
            else cout<<"\nPeeking "<<stack.back()<<endl;
        }
        else if (choice == 6) cout<<"\nNumber of items in Stack is "<<stack.size()<<endl;
        else if (choice == 7) Display(stack);
        else cout<<"Invalid Choice"<<endl;
    }
    
    return 0;
}