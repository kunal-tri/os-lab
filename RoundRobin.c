#include <stdio.h>

struct Process {
	    int pid, arrival, burst, remaining;
};

void RoundRobin(struct Process proc[], int n, int quantum) {
	    int time = 0, completed = 0;
	        
	        for (int i = 0; i < n; i++)
			        proc[i].remaining = proc[i].burst;

		    while (completed != n) { 
			    for (int i = 0; i < n; i++) {
					if (proc[i].remaining > 0) {
						if (proc[i].remaining > quantum)
					 {
						time += quantum;
						proc[i].remaining -= quantum;
					 } 
					 else {
						time += proc[i].remaining;
						proc[i].remaining = 0;
						completed++;
						printf("P%d completed at time %d\n", proc[i].pid, time);
						   }
					}
			}
	 }
}

int main() {
	    struct Process proc[] = {{1, 0, 8}, {2, 1, 4}, {3, 2, 9}, {4, 3, 5}};
	        int n = sizeof(proc) / sizeof(proc[0]);
		    int quantum = 3;

		        RoundRobin(proc, n, quantum);
			    return 0;
}
