#include <stdio.h>
#include <string.h>
#define SIZE 20

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isEmpty(CircularBuffer *cb) {
    int result;
    if (cb->count == 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int isFull(CircularBuffer *cb) {
    int result;
    if (cb->count == SIZE) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer y;
    init(&y);

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    strcat(name, "CE-ESY");
    
    for (int i = 0; name[i] != '\0'; i++) {
        write(&y, name[i]);
    }

    printf("Output: ");
    while (isEmpty(&y) == 0) {
        char value = read(&y);
        printf("%c", value);
    }

    if (isEmpty(&y)) {
        printf("\nBuffer is now empty\n");
    }

    return 0;
}
