#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE (16 + 1)

struct class {
  char class_name[NAME_SIZE];
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

void free_all(struct class *classes, int number_of_classes) {
  /*
  classes (is a pointer) -> struct class -> pointer -> pointer -> char
  */
  struct class *current_class = classes[0];
  for (int i = 0; i < number_of_classes; i++) {
    for (int j = 0; j < current_class.amount_of_campers; j++) {
      free(classes[i].campers[j]);
    }
    free(current_class);
  }
  free(classes);
}

void remove_newline(char *class_name) {
  for (int i = 0; i < NAME_SIZE; i++) {
    if (class_name[i] == '\n') {
      class_name[i] = '\0';
    }
  }
}
// array of chars is the same thing as an array of chars. Square brackets automatically dereference.
int main() {

  int number_of_classes;
  printf("How many classes are there?\n");
  scanf("%d", &number_of_classes);
  struct class *classes = malloc(number_of_classes * sizeof(struct class)); // create the structs for the different class names

  for (int i = 0; i < number_of_classes; i++) {
    fflush(stdin);
    printf("What is the name of class %d?\n", i + 1);
    fgets(classes[i].class_name, NAME_SIZE, stdin);
    remove_newline(classes[i].class_name);

    int amount_of_campers;
    printf("How many campers are taking %s?\n", classes[i].class_name);
    scanf("%d", &amount_of_campers);
    (classes + i)->amount_of_campers = amount_of_campers;

    classes[i].campers = malloc(amount_of_campers * sizeof(char *)); // make array of pointers that point to camper names
    for (int j = 0; j < amount_of_campers; j++) {
      int name_len;
      printf("How many characters are in camper %d's name?\n", j + 1);
      scanf("%d", &name_len);

      printf("Enter camper %d's name:\n", j + 1);
      classes[i].campers[j] = malloc(name_len + 1); // create the char arrays for the camper names
      fflush(stdin);
      fgets(classes[i].campers[j], name_len + 1, stdin);

      printf("%s recorded as %s student #%d.\n", classes[i].campers[j], classes[i].class_name, j + 1);
    }
  }

  // print(names, amount_of_campers);
  free_all(classes, number_of_classes);
  return 0;
}
