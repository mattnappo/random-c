#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct node* append(struct node *tail, int val) {
  tail->next = (struct node *)malloc(sizeof(struct node));
  struct node *newTail = tail->next;
  newTail->val = val;
  newTail->next = NULL;
  return newTail;
}

struct node* remove(struct node *toRemove) {
  if (toRemove->next != NULL) {
    struct node *next = toRemove->next;
    if (next->next != NULL) {
      temp
    } else {

    }
    toRemove->val = toRemove->next->val;
    free()
  }
}

void print(struct node *head) {
  struct node *tempNode = head->next;
  while (tempNode != NULL) {
    printf("%d, ", tempNode->val);
    tempNode = tempNode->next;
  }
}

void free_list(struct node *head) {
  struct node *current = head->next;
  while (current != NULL) {
    struct node *temp = current->next;
    free(current);
    current = temp;
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
   free_list(head);

   return 0;
}
// & takes a object, gets the pointer of the object
// * takes a pointer, gets the object of the pointer
