#include <stdio.h>

struct node {
  int val;
  struct node *next;
};
int main() {
   struct node head = {0, NULL};
   struct node node1 = {10, NULL};
   head.next = &node1;
   struct node node2 = {15, NULL};
   node1.next = &node2;

   struct node *current = head.next;
   while (current != NULL) {
     struct node currentDeref = *current;
     printf("%d\n", currentDeref.val);
     current = currentDeref.next;
   }


   return 0;
}
