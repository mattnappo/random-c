#include <stdio.h>
#include <stdlib.h>

struct class {
  char class_name[16 + 1];
  int amount_of_campers;
  char **campers;
};

void print(char **names, int amount_of_campers) {
  char **current_name = names;
  for (int i = 0; i < amount_of_campers; i++) {
    printf("%s\n", *current_name); // names[i] also works
    current_name++;
  }
}

void free_names(char **names, int amount_of_campers) {
  char **current_name = names;
  for (int i = 0; i < amount_of_campers; i++) {
    free(*current_name);
    current_name++;
  }
  free(names);
}

int main() {
  int number_of_classes;
  printf("How many classes are there?\n")
  scanf("%d", &number_of_classes);
  struct class *classes = malloc(number_of_classes * sizeof(struct class));
  for (int i = 0; i < number_of_classes; i++) {
    fflush(stdin);
    printf("What is the name of this class?\n");
    fgets(classes[i].class_name, 16 + 1, stdin);
    int amount_of_campers;
    printf("How many campers are taking this class?\n");
    scanf("%d", &amount_of_campers);
    (classes + i)->amount_of_campers = amount_of_campers;
    for (int j = 0; j < amount_of_campers; j++) {
      int name_len;
      printf("How many characters are in camper %d's name?\n", j + 1);
      scanf("%d", &name_len);
      printf("Enter camper %d's name:\n", j + 1);
      (classes + i)->campers = malloc(name_len + 1);
      printf("%s recorded.\n", classes[i]);
    }
  }

  print(names, amount_of_campers);
  free_names(names, amount_of_campers);
  return 0;
}
