#include<iostream>
#include<string>
using namespace std;

int main(){
    string str, pattern;

    cout<<"Enter the String: ";
    cin>>str;

    cout<<"Enter the Pattern: ";
    cin>>pattern;

    int start = 0;

    string temp = "";

    for (int i = 0; i < pattern.length(); i++){
        if (pattern.at(i) == '.'){
            temp += pattern.at(i+1);
            start = i+1;
        }
        else{
            temp += pattern.at(i);
        }
    }
    
    pattern = temp;

    temp = "";
    pattern.replace(pattern.find('*'), 1, "");

    for (int i = start; i < str.length(); i++){
        temp += pattern.substr(start, pattern.length());
    }

    pattern += temp;
    pattern = pattern.substr(0, str.length());

    cout<<pattern<<endl;

    if (str == pattern){
        cout<<"Yess....String Matches the Pattern"<<endl;
    }
    else{
        cout<<"Noo....String does not Matches the Pattern"<<endl;
    }

    return 0;
}