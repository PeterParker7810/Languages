#include<iostream>
#include<vector>
using namespace std;

void SubSequence(int index, vector<int>& vec, vector<int>& ds, int check, int* found) {
    if (index == vec.size()) {
        int sum = 0;
        for (auto it : ds) sum += it;
        if (sum == check) {
            cout<<"The Numbers ";
            for (auto it : ds) cout<<it<<" ";
            cout<<"add upto "<<check<<endl;
            (*found) = 1;
            return;
        } else return;
    }

    // Include the current element
    ds.push_back(vec[index]);
    SubSequence(index + 1, vec, ds, check, found);
    ds.pop_back();

    // Exclude the current element
    SubSequence(index + 1, vec, ds, check, found);
}


int main(){
    int size, check, found = 0;
    cout<<"Enter the no of Elements: ";
    cin>>size;

    vector<int> vec(size);
    vector<int> ds;
    for (int i = 0; i < size; i++) {
        cout<<"Enter the Element: ";
        cin>>vec[i];
    }

    cout<<"\nOriginal Array: ";
    for (int i = 0; i < size; i++) cout<<vec[i]<<" ";
    
    cout<<"\n\nEnter number to check: ";
    cin>>check;
    SubSequence(0, vec, ds, check, &found);
    if (!found) cout<<"No Pair Found...";

    return 0;
}