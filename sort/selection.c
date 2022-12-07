#include <stdio.h>

int array[] = {5, 3, 7, 8, 0, 1, 2, 4, 6};
int iterations = 0;

void selection_sort(int array[], int array_length);

void print_array(int array[], int array_length);

int main(void)
{
  int array_length = sizeof(array) / sizeof(array[0]);

  printf("Unordered array: ");
  print_array(array, array_length);

  selection_sort(array, array_length);
  
  printf("Ordered array: ");
  print_array(array, array_length);

  printf("Total of iterations: %i\n", iterations);

  return 0;
}

void selection_sort(int array[], int array_length)
{
  for (int i = 0; i < array_length; i++)
  {
    iterations++;
    int smallest_index = i;
    for (int j = i; j < array_length; j++)
    {
      iterations++;
      if (array[j] < array[smallest_index])
      {
        smallest_index = j;
      }
    }

    if (smallest_index != i)
    {
      int aux = array[smallest_index];
      array[smallest_index] = array[i];
      array[i] = aux;
    }
  }
}

void print_array(int array[], int array_length)
{
  for (int i = 0; i < array_length; i++)
  {
    printf("%i", array[i]);
    if (i < array_length - 1)
    {
      printf(", ");
    }
  }
  printf(".\n");
}