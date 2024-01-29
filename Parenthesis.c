/****************************************************************************
* Purpose:    Parentheses Matching
* Version:    1.0 Nov 6, 2023
* Resources:  
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

struct Stack {
  int top;
  char item[MAX];
};

/*Push an element onto the stack*/
void push(struct Stack *stack, char item) {
  if (stack->top == MAX - 1){
    printf("The stack is full!!\n");
    return;
  }
  stack->item[++stack->top] = item;
}

/*Pop (remove and return) the top element from the stack*/
char pop(struct Stack *stack) {
  if (stack->top == -1) {
    printf("The stack is empty!!\n");
    return -1;
  }
  return stack->item[stack->top--];
}

/*Function to check if it is balanced*/
bool balanced(char *var) {
  struct Stack stack;
  stack.top = -1;
  int x;
  
  for (x = 0; var[x] != '\0'; x++){
    char current = var[x];
    
    if (current == '(' || current == '{' || current == '[') {
      push(&stack, current);
    } else if (current == ')' || current == '}' || current == ']') {
      if (stack.top == -1) {
        return false;
      }
      
      char top = pop(&stack);
      if ((current == ')' && top != '(') || (current == '}' && top != '{') || (current == ']' && top != '[')) {
        return false;
      }
    }
  }
  
  return stack.top == -1;
}

int main() {
  char var[MAX];
  printf("Enter an expression: ");
  fgets(var, MAX, stdin);
  
  if (balanced(var)) {
    printf("It is balanced\n");
  } else {
    printf("It is not balanced\n");
  }
  
  return 0;
}