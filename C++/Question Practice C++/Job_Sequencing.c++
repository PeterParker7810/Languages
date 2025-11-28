#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {int id, deadline, profit;};
bool compare(Job a, Job b) {return a.profit > b.profit;}
void jobSequencing(vector<Job> &jobs) {
    int size = jobs.size(), maxDeadline = 0, totalProfit = 0, jobCount = 0;
    if (size == 0) {
        cout << "No jobs available.\n";
        return;
    }

    sort(jobs.begin(), jobs.end(), compare);
    for (int i = 0; i < size; i++) if (jobs[i].deadline > maxDeadline)
    maxDeadline = jobs[i].deadline;

    vector<int> slot(maxDeadline + 1, -1);
    for (int i = 0; i < size; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    cout<<"\nSelected Jobs (in time order): ";
    for (int i = 1; i <= maxDeadline; i++) if (slot[i] != -1) 
    cout<<"J"<<jobs[slot[i]].id<<" ";
    
    cout<<"\nTotal Jobs Done: "<<jobCount;
    cout<<"\nMaximum Profit: "<<totalProfit<<"\n";
}

int main() {
    int n;
    cout<<"Enter number of jobs: ";
    cin>>n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1; 
        cout<<"\nFor Job-"<<jobs[i].id<<endl;
        cout<<"Enter Profit: ";
        cin>>jobs[i].profit;
        cout<<"Enter Deadline: ";
        cin>>jobs[i].deadline;
    }

    jobSequencing(jobs);

    return 0;
}