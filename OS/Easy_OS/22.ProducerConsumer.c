#include <stdio.h>

#define BUFFER_SIZE 4
int items_in_buffer = 0, items_consumed = 0, empty_slots = BUFFER_SIZE, buffer[BUFFER_SIZE];

int Wait(int value) {
    return (--value);
}

int Signal(int value) {
    return (++value);
}

void produce() {
    int item;

    printf("\nEnter value to Produce : ");
    scanf("%d", &item);

    empty_slots = Wait(empty_slots);
    items_in_buffer = Wait(items_in_buffer);

    buffer[items_consumed] = item;

    items_in_buffer = Signal(items_in_buffer);
    items_consumed = Signal(items_consumed);

    printf("\nBuffer : ");
    for (int i = 0; i < items_consumed; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void consume() {
    items_in_buffer = Wait(items_in_buffer);
    for (int i = 1; i < items_consumed; i++) {
        buffer[i - 1] = buffer[i];
    }
    items_consumed = Wait(items_consumed);
    items_in_buffer = Signal(items_in_buffer);
    empty_slots = Signal(empty_slots);

    printf("\nBuffer : ");

    for (int i = 0; i < items_consumed; ++i) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Hello\n");

    do {
        printf("\n1  -->  Produce\n2  -->  Consume\n3  -->  Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (empty_slots == 0) {
                printf("\nBuffer is full\n");
            }
            else {
                produce();
            }
            break;
        case 2:
            if (empty_slots == BUFFER_SIZE) {
                printf("\nBuffer is empty\n");
            }
            else {
                consume();
            }
            break;
        case 3:
            printf("\nExiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
        }
    } while (choice != BUFFER_SIZE-1);

    return 0;
}
