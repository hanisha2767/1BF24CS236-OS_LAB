#include <stdio.h>

int main() {
    int nb, np, i, j;
    int b[20], p[20], allocation[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of %d memory blocks:\n", nb);
    for (i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of %d processes:\n", np);
    for (i = 0; i < np; i++)
        scanf("%d", &p[i]);

    // ---------- FIRST FIT ----------
    int temp[20];
    for (i = 0; i < nb; i++) temp[i] = b[i];
    for (i = 0; i < np; i++) allocation[i] = -1;

    for (i = 0; i < np; i++) {
        for (j = 0; j < nb; j++) {
            if (temp[j] >= p[i]) {
                allocation[i] = j + 1;
                temp[j] = -1;
                break;
            }
        }
    }

    printf("\n--- First Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, p[i], allocation[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, p[i]);
    }

    // ---------- BEST FIT ----------
    for (i = 0; i < nb; i++) temp[i] = b[i];
    for (i = 0; i < np; i++) allocation[i] = -1;

    for (i = 0; i < np; i++) {
        int bestIdx = -1;
        for (j = 0; j < nb; j++) {
            if (temp[j] >= p[i]) {
                if (bestIdx == -1 || temp[j] < temp[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx + 1;
            temp[bestIdx] = -1;
        }
    }

    printf("\n--- Best Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, p[i], allocation[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, p[i]);
    }

    // ---------- WORST FIT ----------
    for (i = 0; i < nb; i++) temp[i] = b[i];
    for (i = 0; i < np; i++) allocation[i] = -1;

    for (i = 0; i < np; i++) {
        int worstIdx = -1;
        for (j = 0; j < nb; j++) {
            if (temp[j] >= p[i]) {
                if (worstIdx == -1 || temp[j] > temp[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx + 1;
            temp[worstIdx] = -1;
        }
    }

    printf("\n--- Worst Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, p[i], allocation[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, p[i]);
    }

    return 0;
}
