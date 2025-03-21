#include <stdio.h>
#include <limits.h>

struct Process {
	    int pid, arrival, burst, remaining, completion;
};

void SJF_Preemptive(struct Process proc[], int n) {
	    int time = 0, completed = 0, shortest = -1, min_time = INT_MAX;
	        
	        for (int i = 0; i < n; i++)
			    proc[i].remaining = proc[i].burst;

		    while (completed != n) {
			    min_time = INT_MAX;
				for (int i = 0; i < n; i++) 
				{
				if (proc[i].arrival <= time && proc[i].remaining > 0 && proc[i].remaining < min_time) 
				{
			 		min_time = proc[i].remaining;
					shortest = i;
				}
				}

				if (shortest == -1) 
				{
					time++;
					continue;
				}

				proc[shortest].remaining--;
				if (proc[shortest].remaining == 0) 
				{
					completed++;
					proc[shortest].completion = time + 1;
				}
				time++;
			}

		        printf("Process\tCompletion Time\n");
			    for (int i = 0; i < n; i++)
				printf("P%d\t%d\n", proc[i].pid, proc[i].completion);
}

int main() {
	    struct Process proc[] = {{1, 0, 7}, {2, 2, 4}, {3, 4, 1}, {4, 5, 4}};
	        int n = sizeof(proc) / sizeof(proc[0]);

		    SJF_Preemptive(proc, n);
		        return 0;
}
