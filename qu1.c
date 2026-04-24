#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    int size;
    int top1;
    int top2;
    int *arr;
};

bool isFull(struct stack *s) {
    return (s->top1 + 1 == s->top2);
}

bool isEmpty1(struct stack *s) {
    return (s->top1 == -1);
}

bool isEmpty2(struct stack *s) {
    return (s->top2 == s->size);
}

void push1(struct stack *s, int value) {
    if (!isFull(s)) {
        s->arr[++s->top1] = value;
    } else {
        printf("Stack Overflow (Stack 1)\n");
    }
}

void push2(struct stack *s, int value) {
    if (!isFull(s)) {
        s->arr[--s->top2] = value;
    } else {
        printf("Stack Overflow (Stack 2)\n");
    }
}

void pop1(struct stack *s) {
    if (!isEmpty1(s)) {
        printf("Popped from Stack1: %d\n", s->arr[s->top1--]);
    } else {
        printf("Stack1 Underflow\n");
    }
}

void pop2(struct stack *s) {
    if (!isEmpty2(s)) {
        printf("Popped from Stack2: %d\n", s->arr[s->top2++]);
    } else {
        printf("Stack2 Underflow\n");
    }
}

void display1(struct stack *s) {
    if (isEmpty1(s)) {
        printf("Stack1 is empty\n");
        return;
    }
    printf("Stack1: ");
    for (int i = 0; i <= s->top1; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void display2(struct stack *s) {
    if (isEmpty2(s)) {
        printf("Stack2 is empty\n");
        return;
    }
    printf("Stack2: ");
    for (int i = s->size - 1; i >= s->top2; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct stack s;
    s.size = 10;
    s.top1 = -1;
    s.top2 = s.size;

    s.arr = (int*) malloc(sizeof(int) * s.size);

    // Demo operations
    push1(&s, 10);
    push1(&s, 20);
    push2(&s, 100);
    push2(&s, 200);

    display1(&s);
    display2(&s);

    pop1(&s);
    pop2(&s);

    display1(&s);
    display2(&s);

    free(s.arr);
    return 0;
}