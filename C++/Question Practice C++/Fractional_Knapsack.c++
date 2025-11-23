#include<iostream>
#include<vector>
using namespace std;

float KnapSack(vector<float> &profits, vector<float> &weights, vector<float> &pw, int capacity) {
    float result = 0;
    
    while (capacity > 0) {
        int index = -1;
        for (int i = 0; i < pw.size(); i++) if (pw[i] != -1 && (index == -1 || pw[i] > pw[index])) 
        index = i;

        if (index == -1) break;

        if (weights[index] <= capacity) {
            result += profits[index];
            capacity -= weights[index];
            pw[index] = -1;
        } else {
            result += pw[index] * capacity;
            capacity = 0;
        }
    }

    return result;
}

int main(){
    int size, capacity;
    cout<<"Enter the no of Elements: ";
    cin>>size;

    cout<<"Enter the Capacity of Knapsack: ";
    cin>>capacity;

    vector<float> profits(size);
    vector<float> weights(size);
    vector<float> pw(size);
    for (int i = 0; i < size; i++) {
        cout<<"\nFor Element-"<<i+1<<endl;
        cout<<"Enter Profit: ";
        cin>>profits[i];
        cout<<"Enter Weight: ";
        cin>>weights[i];
        pw[i] = float(profits[i]) / weights[i];
    }

    float maxProfit = KnapSack(profits, weights, pw, capacity);
    cout<<"\nMaximum Profit is: "<<maxProfit<<endl;
    
    return 0;
}