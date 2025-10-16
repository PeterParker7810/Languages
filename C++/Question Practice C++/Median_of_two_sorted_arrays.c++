#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> l1;
    vector <int> l2;
    vector <int> l3;
    int limit1,limit2,limit3,elem;

    //Inputting elements for Array-1
    cout<<"Enter no of elements for Array-1: ";
    cin>>limit1;

    cout<<"For Array-1:"<<endl;
    for (int i = 0; i < limit1; i++){
        cout<<"Enter the element: ";
        cin>>elem;
        l1.push_back(elem);
    }

    //Inputting elements for Array-2
    cout<<"\nEnter no of elements for Array-2: ";
    cin>>limit2;

    cout<<"For Array-2:"<<endl;
    for (int i = 0; i < limit2; i++){
        cout<<"Enter the element: ";
        cin>>elem;
        l2.push_back(elem);
    }

    //Merging and sorting the Arrays
    limit3 = limit1 + limit2;

    cout<<"\nElements for Array-1:"<<endl;
    for (int i = 0; i < limit1; i++){
        cout<<l1[i]<<" ";
        l3.push_back(l1[i]);
    }

    cout<<"\nElements for Array-2:"<<endl;
    for (int i = 0; i < limit2; i++){
        cout<<l2[i]<<" ";
        l3.push_back(l2[i]);
    }

    int range = limit3;   //Bubble Sort
    while (range > 0){
        for (int i = 0; i <= range; i++){
            for (int j = i+1; j < range; j++){
                if (l3[i] > l3[j]){
                    l3[i] += l3[j];
                    l3[j] = l3[i] - l3[j];
                    l3[i] -= l3[j];
                }
            }
        }
        range--;
    }

    cout<<"\nElements for Merged Array: "<<endl;
    for (int i = 0; i < limit3; i++){
        cout<<l3[i]<<" ";
    }

    cout<<"\nMedian of Sorted Arrays: ";
    if ((limit3 - 1)%2 == 0){
        cout<<l3[(limit3-1)/2];
    }
    else{
        float avg = (float(l3[(limit3-1)/2]) + float(l3[limit3/2]))/2;
        cout<<avg;
    }

    return 0;
}
