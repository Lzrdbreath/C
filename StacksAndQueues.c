/****************************************************************************
* Purpose:    Implimenting stacks using arrays and queues using linked lists
* Version:    1.0 Oct 27, 2023
* Resources:  
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

/*Stack code*/
int stack[MAX_SIZE]; /*Stack array to hold elements*/
int top = -1; /*Variable to keep track of the top element*/

/*Check if the stack is empty*/
int isEmpty() {
  return top == -1;
}

/*Check if the stack is full*/
int isFull() {
  return top == MAX_SIZE - 1;
}

/*Get the size of the stack*/
int size() {
  return top + 1;
}

/*Get the top element of the stack without removing it*/
int peek() {
  if (isEmpty()) {
    printf("The stack is empty!!\n");
    return -1;
  }
  return stack[top];
}

/*Push an element onto the stack*/
void push(int x) {
  if (top == MAX_SIZE - 1){
    printf("The stack is full!!\n");
    return;
  }
  stack[++top] = x;
}

/*Pop (remove and return) the top element from the stack*/
int pop() {
  if (top == -1) {
    printf("The stack is empty!!\n");
    return -1;
  }
  return stack[top--];
}

/*Queue code*/
struct Node {
  int data;
  struct Node *next;
};
typedef struct Node Node;

struct queue {
  int count;
  Node *front;
  Node *rear;
};
typedef struct queue queue;

/*Check if the queue is empty*/
int isempty(queue *q) {
  return (q->rear == NULL);
}

/*Enqueue (add) an element to the queue*/
void enqueue(queue *q, int x) {
  
  if (q->count < MAX_SIZE) {
    Node *tmp;
    tmp = malloc(sizeof(Node));
    tmp->data = x;
    tmp->next = NULL;
    
    if(!isempty(q)) {
      q->rear->next = tmp;
      q->rear = tmp;
    }
    
    else {
      q->front = q->rear = tmp;
    }
    
    q->count++;
  }
  
  else {
    printf("Queue is full\n");
  }
}

/*Dequeue (remove and return) an element from the queue*/
int dequeue(queue *q) {
  if (isempty(q)){
    printf("The queue is empty\n");
    return -1;
  }
  else {
    Node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return n;
  }
}

/*Get and print the element at the front of the queue without removing it*/
void front(queue *q) {
  
  if (q->front == NULL) {
    printf("The queue is empty\n");
  }
  
  else {
    printf("%d\n", q->front->data);
  }
}

int main() {
  int ans, x, soq;
  queue q;
  
  printf("Would you like to interact with a queue(1) or a stack(2)? Only one choice per run\n");
  printf("Enter 1 or 2: ");
  scanf("%d", &soq);

/*Queue code*/ 
  if (soq == 1) {
    q.count = 0;
    q.front = q.rear = NULL;
  
    while (1) {
      
      printf("1. isEmpty\n2. size\n3. front\n4. enqueue\n5. dequeue\n6. exit\n");
      printf("Please select an option: ");
      scanf("%d", &ans);
      
      if (ans == 1) {
        if (isempty(&q)){
          printf("The queue is empty.\n");
        }
        else {
          printf("The queue has items in it.\n");
        }
      }
      
      else if (ans == 2) {
        printf("The size is %d\n", q.count);
      }
      
      else if (ans == 3) {
        front(&q);
      }
      
      else if (ans == 4) {
        printf("Enter a number to enqueue: ");
        scanf("%d", &x);
        enqueue(&q, x);
      }
      
      else if (ans == 5) {
        x = dequeue(&q); 
        if (x != -1) {
          printf("Dequeued: %d\n", x);
        }
      }
      
      else if (ans == 6) {
        printf("Exiting... Goodbye.");
        exit(0);
      }
      
      else {
        printf("Invalid operation\n");
      }
    }
  }
  
  /*Stack code*/
  else if (soq == 2) {
    
    while (1) {
      printf("1. isEmpty\n2. isFull\n3. size\n4. top/peek\n5. push\n6. pop\n7. exit\n");
      printf("Please select an option: ");
      scanf("%d", &ans);
      
      if (ans == 1) {
        if (isEmpty()){
          printf("The stack is empty.\n");
        }
        else {
          printf("The stack has items in it.\n");
        }
      }
      
      else if (ans == 2) {
        if (isFull()){
          printf("The stack is full.\n");
        }
        else {
          printf("The stack is not full.\n");
        }
      }
      
      else if (ans == 3) {
        printf("The size is %d\n", size());
      }
      
      else if (ans == 4) {
        x = peek();
        if (x != -1) {
          printf("The top element is %d\n", x);
        }
      }
      
      else if (ans == 5) {
        printf("Enter a number to push: ");
        scanf("%d", &x);
        push(x);
      }
      
      else if (ans == 6) {
        x = pop();
        if (x != -1) {
          printf("Popped: %d\n", x);
        }
      }
      
      else if (ans == 7) {
        printf("Exiting... Goodbye.");
        exit(0);
      }
      
      else {
        printf("Invalid operation\n");
      }
    }
  }
  
  /*Exeption handling code*/
  else {
    printf("Invalid Input\n");
  }
  
  return 0;
}