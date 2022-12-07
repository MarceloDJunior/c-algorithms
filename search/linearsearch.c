#include <stdio.h>

int array_size = 300;

int find_index(int number_to_find, int numbers[]);

void seed_array(int array[]);

int main(void) {
  int numbers[array_size];
  int number_to_find;
  seed_array(numbers);
  printf("Input a value between 1 and %i: ", array_size);
  scanf("%i", &number_to_find);
  int found_value = find_index(number_to_find, numbers);
  if (found_value == -1) {
    printf("Value not found.\n");
  } else {
    printf("Value found at index %i\n", found_value);
  }
  return 0;
}

void seed_array(int array[]) {
  for (int i = 0; i < array_size ;i++) {
    array[i] = i + 1;
  }
}

int find_index(int number_to_find, int numbers[]) {
  for (int i = 0; i < array_size; i++) {
    printf("Checking the index %i (value: %i)...\n", i, numbers[i]);
    if (numbers[i] == number_to_find) {
      return i;
    }
  }
  return -1;
}