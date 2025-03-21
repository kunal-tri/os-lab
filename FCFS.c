#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    struct Process* next;
};

void insertProcess(struct Process** head, int pid, int arrival_time, int burst_time) {
    struct Process* new_process = (struct Process*)malloc(sizeof(struct Process));
    new_process->pid = pid;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
        return;
    }

    struct Process* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_process;
}

void FCFS(struct Process* head) {
    int time = 0, wait_time = 0, turnaround_time = 0;
    struct Process* temp = head;

    printf("Process Execution Order: \n");
    while (temp != NULL) {
        if (time < temp->arrival_time)
            time = temp->arrival_time;
        wait_time += time - temp->arrival_time;
        turnaround_time += wait_time + temp->burst_time;
        printf("P%d ", temp->pid);
        time += temp->burst_time;
        temp = temp->next;
    }

    printf("\nAverage Waiting Time: %.2f", (float)wait_time / 3);
    printf("\nAverage Turnaround Time: %.2f\n", (float)turnaround_time / 3);
}

int main() {
    struct Process* head = NULL;
    insertProcess(&head, 1, 0, 5);
    insertProcess(&head, 2, 1, 3);
    insertProcess(&head, 3, 2, 8);
    
    FCFS(head);
    return 0;
}
