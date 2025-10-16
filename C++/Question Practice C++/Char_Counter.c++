#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void Count(vector <char>& ar, vector <int>& ar1){
    for (int i = 0; i < ar.size(); i++){
        int count = 0;
        for (int j = 0; j < ar.size(); j++){
            if (ar[i] == ar[j]){
                count++;
            }
        }
        ar1.push_back(count);
    }
}

int main(){
    string user, out = "";
    cout<<"Enter the String: ";
    cin>>user;

    vector <char> vec;
    vector <int> count;

    for (int i = 0; i < user.size(); i++){
        vec.push_back(user[i]);
    }

    Count(vec, count);

    auto it = unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
    
    auto it1 = unique(count.begin(), count.end());
    count.erase(it1, count.end());

    for (int i = 0; i < count.size(); i++){
        out.append(to_string(count[i]));
        out.append(1, vec[i]);
    }

    cout<<"Output String: "<<out<<endl;

    return 0;
}
