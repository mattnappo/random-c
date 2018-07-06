#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE (16 + 1)

struct class {
  char class_name[NAME_SIZE];
  int amount_of_campers;
  char **campers;
};

void print(struct class *classes, int number_of_classes) {
  // classes (is a pointer) -> struct class -> pointer -> pointer -> char
  struct class current_class = classes[0];
  for (int i = 0; i < number_of_classes; i++) {
    printf("%s students:\n", current_class.class_name);
    for (int j = 0; j < current_class.amount_of_campers; j++) {
      char *current_name = current_class.campers[j];
      printf("%s\n", current_name);
    }
    current_class = classes[i + 1];
  }
}

void free_all(struct class *classes, int number_of_classes) {
  // classes (is a pointer) -> struct class -> pointer -> pointer -> char
  struct class current_class = classes[0];
  for (int i = 0; i < number_of_classes; i++) {
    for (int j = 0; j < current_class.amount_of_campers; j++) {
      char *current_name = current_class.campers[j];
      free(current_name);
    }
    free(current_class.campers);
    current_class = classes[i + 1];
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
  char temp[16];
  fgets(temp, 16, stdin);
  sscanf(temp, "%d", &number_of_classes);
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
  print(classes, number_of_classes);
  free_all(classes, number_of_classes);
  return 0;
}
