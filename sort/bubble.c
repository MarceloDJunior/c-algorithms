#include <stdio.h>

int array[] = {5, 3, 7, 8, 0, 1, 2, 4, 6};
int iterations = 0;

void bubble_sort(int array[], int array_length);

void print_array(int array[], int array_length);

int main(void)
{
  int array_length = sizeof(array) / sizeof(array[0]);

  printf("Unordered array: ");
  print_array(array, array_length);

  bubble_sort(array, array_length);

  printf("Ordered array: ");
  print_array(array, array_length);

  printf("Total of iterations: %i\n", iterations);

  return 0;
}

void bubble_sort(int array[], int array_length)
{
  for (int i = 0; i < array_length - 1; i++)
  {
    iterations++;
    int num_swaps = 0;
    for (int j = 0; j < array_length - 1 - i; j++)
    {
      iterations++;
      if (array[j] > array[j + 1])
      {
        num_swaps++;
        int aux = array[j];
        array[j] = array[j + 1];
        array[j + 1] = aux;
      }
    }
    if (num_swaps == 0)
    {
      break;
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
  printf("\n");
}