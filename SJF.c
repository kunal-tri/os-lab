#include <stdio.h>

struct Process {
	    int pid, arrival, burst, waiting, turnaround;
};

void sortProcesses(struct Process proc[], int n) 
{
	    for (int i = 0; i < n-1; i++) 
		{
		    for (int j = i+1; j < n; j++) 
			{
				if (proc[i].burst > proc[j].burst) 
				{
					struct Process temp = proc[i];
					proc[i] = proc[j];
					proc[j] = temp;
				}
			}
		}
}

void calculateTimes(struct Process proc[], int n) {
	    proc[0].waiting = 0;
	        proc[0].turnaround = proc[0].burst;

		    for (int i = 1; i < n; i++) {
			            proc[i].waiting = proc[i - 1].waiting + proc[i - 1].burst;
				            proc[i].turnaround = proc[i].waiting + proc[i].burst;
					        }
}

void SJF(struct Process proc[], int n) {
	    sortProcesses(proc, n);
	        calculateTimes(proc, n);

		    printf("Process\tWaiting Time\tTurnaround Time\n");
		        for (int i = 0; i < n; i++)
				        printf("P%d\t%d\t\t%d\n", proc[i].pid, proc[i].waiting, proc[i].turnaround);
}

int main() {
	    struct Process proc[] = {{1, 0, 6}, {2, 1, 2}, {3, 2, 8}, {4, 3, 3}};
	        int n = sizeof(proc) / sizeof(proc[0]);

		    SJF(proc, n);
		        return 0;
}
