#include <stdio.h>
#include <stdlib.h>
#include "listHeader.h"

struct node* append(struct node *tail, int val) {
  tail->next = (struct node *)malloc(sizeof(struct node));
  struct node *newTail = tail->next;
  newTail->val = val;
  newTail->next = NULL;
  return newTail;
}

void test(int i) {
  printf("%d\n", i);
}

int remove_node(struct node *to_remove) {
  if (to_remove->next != NULL) {
    struct node *next = to_remove->next;
    struct node *after = next->next;
    to_remove->val = next->val;
    free(next);
    to_remove->next = after;
    free(after);
    return 0;
  }
  return 1;
}

void print(struct node *head) {
  struct node *tempNode = head->next;
  while (tempNode != NULL) {
    printf("%d \n", tempNode->val);
    tempNode = tempNode->next;
  }
}

int main() {
   struct node headNode = {0, NULL};
   struct node *head = &headNode;
   struct node *tail = head;
   int shouldPrompt = 1;
   while (shouldPrompt) {
     int input;
     printf("How many numbers do you want to enter?\n");
     scanf("%d", &input);
     if (input == 0) {
       shouldPrompt = 0;
     } else {
       for (int i = 0; i < input; i++) {
         int val;
         printf("Number %d\n", i + 1);
         scanf("%d", &val);
         tail = append(tail, val);
       }
       shouldPrompt = 0;
     }
   }
   print(head);
   if (!remove_node(head->next)) {
     printf("You can not remove the tail.\n");
   }
   print(head);
   free_list(head);
   return 0;
}

void free_list(struct node *head) {
  struct node *current = head->next;
  while (current != NULL) {
    struct node *temp = current->next;
    free(current);
    current = temp;
  }
}

// & takes a object, gets the pointer of the object
// * takes a pointer, gets the object of the pointer
