#include<iostream>
using namespace std;

int main(){
    int limit;
    cout<<"Enter the limit: ";
    cin>>limit;

    //Pattern-1
    cout<<"\nPattern-1:"<<endl;
    for (int i = 1; i <= limit; i++){
        for (int j = 1; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //pattern-2
    cout<<"\nPattern-2:"<<endl;
    for (int i = 0; i < limit; i++){
        for (int j = 1; j <= i; j++){
            cout<<"  ";
        }
        for (int k = limit; k > i; k--){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-3
    cout<<"\nPattern-3:"<<endl;
    for (int i = limit; i > 0; i--){
        for (int j = 1; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-4
    cout<<"\nPattern-4:"<<endl;
    for (int i = 1; i <= limit; i++){
        for (int j = limit; j > i; j--){
            cout<<"  ";
        }
        for (int k = 1; k <= i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-5
    cout<<"\nPattern-5:"<<endl;
    for (int i = 1; i <= limit; i++){
        for (int j = 1; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-6
    cout<<"\nPattern-6:"<<endl;
    for (int i = 1; i <= limit; i++){
        for (int j = limit; j > i; j--){
            cout<<"  ";
        }
        for (int k = 1; k <= i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            cout<<"  ";
        }
        for (int k = limit-1; k > i; k--){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-7
    cout<<"\nPattern-7:"<<endl;
    for (int i = 1; i <= limit; i++){
        for (int j = limit; j > i; j--){
            cout<<" ";
        }
        for (int k = 1; k <= i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            cout<<" ";
        }
        for (int k = limit-1; k > i; k--){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-8
    cout<<"\nPattern-8:"<<endl;
    int temp = 1;
    for (int i = 1; i <= (limit*2); i++){
        if (i%2 == 0){
            for (int j = limit*2; j >= i; j--){
                cout<<" ";
            }
        }
        else{
            for (int j = limit*2; j > i; j--){
                cout<<" ";
            }
        }
        for (int k = 1; k <= temp; k++){
            cout<<"* ";
        }
        cout<<endl;
        if (i%2 == 0){
            temp += 2;
        }
    }

    //Pattern-9
    cout<<"\nPattern-9:"<<endl;
    for (int i = 0; i < limit; i++){
        for (int j = 1; j <= i; j++){
            cout<<" ";
        }
        if (i != limit-1){
            for (int k = limit; k > i; k--){
                cout<<"* ";
            }
        cout<<endl;
        }
    }

    for (int i = 1; i <= limit; i++){
        if (i != 1){
            for (int j = limit; j > i; j--){
                cout<<" ";
            }
        }
        for (int k = 1; k <= i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-10
    cout<<"\nPattern-10:"<<endl;
    for (int i = 1; i <= limit; i++){
        for (int j = limit; j > i; j--){
            cout<<" ";
        }
        temp = 0;
        for (int k = 1; k <= i; k++){
            if (temp == 0){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }

            if (k == i-1){
                temp = 0;
            }
            else{
                temp++;
            }
        }
        cout<<endl;
    }

    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            cout<<" ";
        }
        temp = 0;
        for (int k = limit-1; k > i; k--){
            if (temp == 0){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }

            if (k == i+2){
                temp = 0;
            }
            else{
                temp++;
            }
        }
        cout<<endl;
    }

    //Pattern-11
    cout<<"\nPattern-11:"<<endl;
    for (int i = limit; i > 0; i--){
        temp = 0;
        for (int j = 1; j <= limit; j++){
            if (i == limit || i == 1){
                cout<<"* "; 
            }

            else{
                if (temp == 0){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }

                if (j == limit-1){
                    temp = 0;
                }
                else{
                    temp++;
                }              
            }
        }
        cout<<endl;
    }

    //Pattern-12
    cout<<"\nPattern-12:"<<endl;
    for (int i = 1; i <= limit; i++){
        for (int j = limit; j > i; j--){
            cout<<" ";
        }
        temp = 0;
        for (int k = 1; k <= i; k++){
            if (i == limit){
                cout<<"* ";
            }
            else{
                if (temp == 0){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }

                if (k == i-1){
                    temp = 0;
                }
                else{
                    temp++;
                }
            }
        }
        cout<<endl;
    }

    //Pattern-13
    cout<<"\nPattern-13:"<<endl;
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            cout<<" ";
        }
        temp = 0;
        for (int k = limit; k > i; k--){
            if (i == 0){
                cout<<"* ";
            }
            else{
                if (temp == 0){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }

                if (k == i+2){
                    temp = 0;
                }
                else{
                    temp++;
                }
            }
        }
        cout<<endl;
    }

    //Pattern-14
    cout<<"\nPattern-14:"<<endl;
    for (int i = 0; i < limit; i++){
        for (int j = 1; j <= i; j++){
            cout<<"  ";
        }
        for (int k = 1; k <= limit; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //Pattern-15
    cout<<"\nPattern-15:"<<endl;
    for (int i = 0; i < limit; i++){
        for (int j = 1; j <= i; j++){
            cout<<" ";
        }
        temp = 0;
        for (int k = limit; k > i; k--){
            if (i == limit-1){
                cout<<"";
            }
            else{
                if (i == 0){
                    cout<<"* ";
                }
                else{
                    if (temp == 0){
                        cout<<"* ";
                    }
                    else{
                        cout<<"  ";
                    }

                    if (k == i+2){
                        temp = 0;
                    }
                    else{
                        temp++;
                    }
                }
            }

        }
        if (i != limit-1){
            cout<<endl;
        }
    }

    for (int i = 1; i <= limit; i++){
        if (i != 1){
            for (int j = limit; j > i; j--){
                cout<<" ";
            }
        }
        temp = 0;
        for (int k = 1; k <= i; k++){
            if (i == limit){
                cout<<"* ";
            }
            else{
                if (temp == 0){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }

                if (k == i-1){
                    temp = 0;
                }
                else{
                    temp++;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}