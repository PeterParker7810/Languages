#include<iostream>
#include<vector>
using namespace std;

void SubSequence(int index, vector<int>& vec, vector<int>& ds) {
    if (index == vec.size()) {
        for (auto it : ds) cout<<it<<" ";
        cout<<endl;
        return;
    }

    // Include the current element
    ds.push_back(vec[index]);
    SubSequence(index + 1, vec, ds);
    ds.pop_back();

    // Exclude the current element
    SubSequence(index + 1, vec, ds);
}


int main(){
    int size;
    cout<<"Enter the no of Elements: ";
    cin>>size;

    vector<int> vec(size);
    vector<int> ds;
    for (int i = 0; i < size; i++) {
        cout<<"Enter the Element: ";
        cin>>vec[i];
    }

    cout<<"\nOriginal Array: ";
    for (auto it : vec) cout<<it<<" ";
    
    cout<<"\n\nAll Subsequences are: "<<endl;
    cout<<"{}"<<endl;
    SubSequence(0, vec, ds);
    
    return 0;
}