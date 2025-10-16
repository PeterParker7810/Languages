#include<iostream>
#include<string>
using namespace std;

int main(){
    int num,arr[4];
    string roman[4];
    cout<<"Enter the number: ";
    cin>>num;

    if (num < 4000){
        // Adding Numbers in Array
        int mult = 1;
        for (int i = 0; i < 4; i++){
            arr[i] = (num%10)*mult;
            num /= 10;
            mult *= 10;
        }

        // Changing to Roman
        for (int i = 3; i >= 0; i--){
            if (i == 3){
                for (int j = 0; j < int(arr[i]/1000); j++){
                    roman[i] = roman[i].append("M");
                }
            }

            else if (i == 2){
                if (arr[i] == 400){
                    roman[i] = "CD";
                }
                else if (arr[i] == 500){
                    roman[i] = "D";
                }
                else if (arr[i] == 900){
                    roman[i] = "CM";
                }
                else if (arr[i] < 400){
                    for (int j = 0; j < int(arr[i]/100); j++){
                        roman[i] = roman[i].append("C");
                    }
                }
                else if (arr[i] > 500){
                    roman[i] = "D";
                    for (int j = 0; j < int((arr[i]-500)/100); j++){
                        roman[i] = roman[i].append("C");
                    }
                }
            }

            else if (i == 1){
                if (arr[i] == 40){
                    roman[i] = "XL";
                }
                else if (arr[i] == 50){
                    roman[i] = "L";
                }
                else if (arr[i] == 90){
                    roman[i] = "CX";
                }
                else if (arr[i] < 40){
                    for (int j = 0; j < int(arr[i]/10); j++){
                        roman[i] = roman[i].append("X");
                    }
                }
                else if (arr[i] > 50){
                    roman[i] = "L";
                    for (int j = 0; j < int((arr[i]-50)/10); j++){
                        roman[i] = roman[i].append("X");
                    }
                }
            }

            else if (i == 0){
                if (arr[i] == 4){
                    roman[i] = "IV";
                }
                else if (arr[i] == 5){
                    roman[i] = "V";
                }
                else if (arr[i] == 9){
                    roman[i] = "IX";
                }
                else if (arr[i] < 4){
                    for (int j = 0; j < int(arr[i]); j++){
                        roman[i] = roman[i].append("I");
                    }
                }
                else if (arr[i] > 5){
                    roman[i] = "V";
                    for (int j = 0; j < int((arr[i]-5)); j++){
                        roman[i] = roman[i].append("I");
                    }
                }
            }
        }

        cout<<"Number in Roman: ";
        for (int i = 3; i >= 0; i--){
            cout<<roman[i];
        }
    }

    else{
        cout<<"Enter number in Range 1-3999";
    }
    
    return 0;
}