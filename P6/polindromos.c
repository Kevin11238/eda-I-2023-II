#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int front;
    int rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

void insertFront(Deque *dq, char item) {
    if (isFull(dq)) {
        printf("Queue is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->data[dq->front] = item;
}

void insertRear(Deque *dq, char item) {
    if (isFull(dq)) {
        printf("Queue is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->data[dq->rear] = item;
}

char deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty\n");
        return '\0';
    }
    char item = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return item;
}

char deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty\n");
        return '\0';
    }
    char item = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    return item;
}

int isPalindrome(Deque *dq, char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        insertRear(dq, str[i]);
    }
    while (dq->front != dq->rear && dq->front != dq->rear + 1) {
        char front = deleteFront(dq);
        char rear = deleteRear(dq);
        if (front != rear) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Deque dq;
    initDeque(&dq);

    char str[MAX];
    printf("Ingrese la palabra a evaluar: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(&dq, str)) {
        printf("La cadena es un palindromo.\n");
    } 
	else {
        printf("La cadena NO es un palindromo.\n");
    }

    return 0;
}

