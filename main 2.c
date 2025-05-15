#include <stdio.h>

int main() {
    char pn[10][10];  // Array to store process names
    int arr[10], bur[10];  // Arrays for Arrival Time and Burst Time
    int star[10], finish[10];  // Arrays for Start Time and Finish Time
    int tat[10], wt[10];  // Arrays for Turnaround Time and Waiting Time
    int i, n;  // Loop variable and number of processes
    int totwt = 0, tottat = 0;  // Total waiting time and turnaround time

    printf("Enter the number of processes:");
    scanf("%d", &n);  // Input number of processes

    // Input process name, arrival time, and burst time
    for (i = 0; i < n; i++) {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf("%s %d %d", pn[i], &arr[i], &bur[i]);
    }

    // Calculate start time, waiting time, finish time, turnaround time
    for (i = 0; i < n; i++) {
        if (i == 0) {
            star[i] = arr[i];  // Start time is arrival time for first process
        } else {
            star[i] = finish[i - 1];  // Start time = finish time of previous process
        }
        wt[i] = star[i] - arr[i];  // Waiting time
        finish[i] = star[i] + bur[i];  // Finish time
        tat[i] = finish[i] - arr[i];  // Turnaround time

        totwt += wt[i];
        tottat += tat[i];
    }

    // Print table header
    printf("\nPName Arrtime Burtime Start TAT Finish\n");

    // Print process details
    for (i = 0; i < n; i++) {
        printf("%s\t%6d\t%6d\t%6d\t%6d\t%6d\n", pn[i], arr[i], bur[i], star[i], tat[i], finish[i]);
    }

    // Print average waiting time and average turnaround time
    printf("Average Waiting time: %.2f\n", (float)totwt / n);
    printf("Average Turn Around Time: %.2f\n", (float)tottat / n);

    return 0;
}
