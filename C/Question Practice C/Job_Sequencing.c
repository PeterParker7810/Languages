#include<stdio.h>
#include<stdlib.h>

typedef struct Jobs {int id, deadline, profit;} Jobs;
void Merge(Jobs arr[], int start, int mid, int end) {
    int sizeL = mid-start+1;
    int sizeR = end-mid;
    
    Jobs* Left = (Jobs*)malloc(sizeL * sizeof(Jobs));
    Jobs* Right = (Jobs*)malloc(sizeR * sizeof(Jobs));

    for (int i = 0; i < sizeL; i++) Left[i] = arr[start+i];
    for (int i = 0; i < sizeR; i++) Right[i] = arr[mid+i+1];

    int i = 0, j = 0, k = start;
    while (i < sizeL && j < sizeR) {
        if (Left[i].profit >= Right[j].profit) arr[k++] = Left[i++];
        else arr[k++] = Right[j++];
    }

    while (i < sizeL) arr[k++] = Left[i++];
    while (j < sizeR) arr[k++] = Right[j++];

    free(Left);
    free(Right);
}

void MergeSort(Jobs arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end-start)/2;

        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);

        Merge(arr, start, mid, end);
    }
}

void JobSequence(Jobs jobs[], int size) {
    int maxDeadline = 0, totalProfit = 0, jobCount = 0;
    if (size == 0) {
        printf("No jobs available\n");
        return;
    }

    MergeSort(jobs, 0, size-1);
    for (int i = 0; i < size; i++) if (jobs[i].deadline > maxDeadline)
    maxDeadline = jobs[i].deadline;

    int* slot = (int*)malloc((maxDeadline+1) * sizeof(int));
    for (int i = 0; i < maxDeadline+1; i++) slot[i] = -1;

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

    printf("\nSelected Jobs (in time order): ");
    for (int i = 0; i <= maxDeadline; i++) if (slot[i] != -1)
    printf("Job%d ", jobs[slot[i]].id);

    printf("\nTotal Jobs Done: %d", jobCount);
    printf("\nTotal Profit: %d\n", totalProfit);
    free(slot);
}

int main(){
    int n;
    printf("Enter no of Jobs: ");
    scanf("%d", &n);

    Jobs* jobs = (Jobs*)malloc(n * sizeof(Jobs));
    for (int i = 0; i < n; i++) {
        jobs[i].id = i+1;
        printf("For Job-%d\n", jobs[i].id);
        printf("Enter Profit: ");
        scanf("%d", &jobs[i].profit);
        printf("Enter Deadline: ");
        scanf("%d", &jobs[i].deadline);
    }
    
    JobSequence(jobs, n);
    free(jobs);

    return 0;
}