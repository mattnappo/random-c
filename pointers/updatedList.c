#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct node* append(struct node *tail, int val) {
  struct node *newNode = (*tail).next;
  newNode = (struct node *)malloc(sizeof(struct node));
  struct node derefNode = *newNode;
  derefNode.val = val;
  derefNode.next = NULL;
  return newNode;
}

void print(struct node *head) {
  struct node *tempNode = (*head).next;
  while (tempNode != NULL) {
    struct node tempNodeDeref = *tempNode;
    printf("%d\n", tempNodeDeref.val);
    tempNode = tempNodeDeref.next;
  }
}

int main() {
   struct node head = {0, NULL};
   int shouldPrompt = 1;
   while(shouldPrompt) {
     int input;
     printf("How many numbers do you want to enter?\n");
     scanf("%d", &input);
     if (input == 0) {
       shouldPrompt = 0;
     } else {
       for (int i = 0; i < input + 1; i++) {
         int val;
         printf("Number %d\n", i);
         scanf("%d", &val);
         append(&head, val);
       }
       shouldPrompt = 0;
     }

   }
   print(&head);

   // & takes a object, gets the pointer of the object
   // * takes a pointer, gets the object of the pointer


   return 0;
}
