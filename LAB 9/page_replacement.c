#include <stdio.h>

int frames[10];

/* Function to check if page exists in frames */
int search(int key, int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == key)
            return 1;
    }
    return 0;
}

/* FIFO Page Replacement */
void FIFO(int pages[], int n, int frameCount) {
    int pageFaults = 0, index = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\n--- FIFO Page Replacement ---\n");

    for (int i = 0; i < n; i++) {
        if (!search(pages[i], frameCount)) {
            frames[index] = pages[i];
            index = (index + 1) % frameCount;
            pageFaults++;
        }

        printf("Page %d -> ", pages[i]);
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);
}

/* LRU Page Replacement */
void LRU(int pages[], int n, int frameCount) {
    int pageFaults = 0, time[10], counter = 0;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\n--- LRU Page Replacement ---\n");

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = 0;

            for (int j = 1; j < frameCount; j++) {
                if (time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            pageFaults++;
        }

        printf("Page %d -> ", pages[i]);
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);
}

/* Optimal Page Replacement */
void Optimal(int pages[], int n, int frameCount) {
    int pageFaults = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\n--- Optimal Page Replacement ---\n");

    for (int i = 0; i < n; i++) {

        if (search(pages[i], frameCount)) {
            printf("Page %d -> ", pages[i]);

            for (int j = 0; j < frameCount; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\n");

            continue;
        }

        int pos = -1, farthest = i + 1;

        for (int j = 0; j < frameCount; j++) {
            int k;

            for (k = i + 1; k < n; k++) {
                if (frames[j] == pages[k]) {
                    if (k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                    break;
                }
            }

            if (k == n) {
                pos = j;
                break;
            }
        }

        if (pos == -1)
            pos = 0;

        frames[pos] = pages[i];
        pageFaults++;

        printf("Page %d -> ", pages[i]);

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);
}

int main() {
    int pages[50], n, frameCount, choice;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    printf("\nChoose Algorithm:");
    printf("\n1. FIFO");
    printf("\n2. LRU");
    printf("\n3. Optimal");
    printf("\n4. All Algorithms");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FIFO(pages, n, frameCount);
            break;

        case 2:
            LRU(pages, n, frameCount);
            break;

        case 3:
            Optimal(pages, n, frameCount);
            break;

        case 4:
            FIFO(pages, n, frameCount);
            LRU(pages, n, frameCount);
            Optimal(pages, n, frameCount);
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}
