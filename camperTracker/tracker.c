#include <stdio.h>
#include <stdlib.h>

void print(char **names, int amount_of_campers) {
  for (int i = 0; i < amount_of_campers; i++) {
    printf("%s\n", *(names + i)); // names[i] also works
  }
}

int main() {
  int amount_of_campers;
  printf("How many campers do you want?\n");
  scanf("%d", &amount_of_campers);
  // printf("%d", amount_of_campers);
  char **names = malloc(amount_of_campers * sizeof(char *));
  for (int i = 0; i < amount_of_campers; i++) {
    int name_len;
    printf("How many characters are in camper %d's name?\n", i + 1);
    scanf("%d", &name_len);
    fflush (stdin);
    printf("Enter the camper's name:\n");
    names[i] = malloc(name_len + 1);
    fgets(names[i], name_len + 1, stdin);
    printf("%s recorded. \n", names[i]);
  }
  print(names, amount_of_campers);
  free(names); // free all the mallocs
  return 0;
}
