#include <stdio.h>
#include <stdlib.h>

int main() {
  int amount_of_campers;
  printf("How many campers do you want?\n");
  scanf("%d", amount_of_campers);
  char *names[] = (char **)malloc(amount_of_campers * sizeof(char *));
  for (i = 0; i < amount_of_campers; i++) {
    int name_len;
    printf("How many characters are in this camper's name?\n");
    scanf("%d", name_len);
    printf("Enter the camper's name: ");
    names[i] = malloc(name_len + 1);
    fgets(names[i], name_len + 1, stdin);
  }
  free(names);
}
