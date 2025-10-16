#include<iostream>
#include<vector>
using namespace std;

int BubbleSort(vector <int> (&arr)){
    int range = arr.size();
    while (range > 0){
        for (int i = 0; i <= range; i++){
            for (int j = i+1; j < range; j++){
                if (arr[i] > arr[j]){
                    arr[i] += arr[j];
                    arr[j] = arr[i] - arr[j];
                    arr[i] -= arr[j];
                }
            }
        }
        range--;
    }
}

int main(){
    int Final[100][100], sizes[100];
    vector <int> out;
    int quant;

    cout<<"Enter no of Lists: ";
    cin>>quant;

    //Inputting Data
    for (int i = 0; i < quant; i++){
        vector <int> vec;
        int limit, elem;

        cout<<"\nFor List-"<<i+1<<endl;
        cout<<"Enter the no of elements: ";
        cin>>limit;

        sizes[i] = limit;
        for (int j = 0; j < limit; j++){
            cout<<"Enter the element: ";
            cin>>elem;
            vec.push_back(elem);
        }
        BubbleSort(vec);

        for (int k = 0; k < vec.size(); k++){
            Final[i][k] = vec[k];
            elem = vec[k];
            out.push_back(elem);
        }
        BubbleSort(out);
    }

    //Printing Output
    cout<<"\nInputted List: "<<endl<<"[";
    for (int i = 0; i < quant; i++){
        cout<<"[";
        for (int j = 0; j < sizes[i]; j++){
            cout<<Final[i][j];
            if (j != (sizes[i]-1)){
                cout<<",";
            }
        }
        cout<<"]";
        if (i != (quant-1)){
            cout<<",";
        }
    }
    cout<<"]"<<endl;

    cout<<"\nOutput List: "<<endl<<"[";
    for (int i = 0; i < out.size(); i++){
        cout<<out[i];
        if (i != (out.size()-1)){
            cout<<",";
        }
    }
    cout<<"]";

    return 0;
}