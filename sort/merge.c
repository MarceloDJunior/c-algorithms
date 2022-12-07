#include <stdio.h>

int array[] = {5, 3, 7, 8, 0, 1, 2, 4, 6};
int iterations = 0;

void merge_sort(int array[], int left, int right);

void merge(int array[], int left, int middle, int right);

void print_array(int array[], int array_length);

int main(void)
{
  int array_length = sizeof(array) / sizeof(array[0]);

  printf("Unordered array: ");
  print_array(array, array_length);

  merge_sort(array, 0, array_length - 1);

  printf("Ordered array: ");
  print_array(array, array_length);

  printf("Total of iterations: %i\n", iterations);

  return 0;
}

// Divide the array into two subarrays, sort them and merge them
void merge_sort(int array[], int left, int right)
{
  if (left < right)
  {
    int middle = left + (right - left) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    // Merge the sorted subarrays
    merge(array, left, middle, right);
  }
}

// Merge subarrays
void merge(int array[], int left, int middle, int right)
{
  int left_size = middle - left + 1;
  int right_size = right - middle;

  int left_array[left_size];
  int right_array[right_size];

  for (int i = 0; i < left_size; i++)
  {
    left_array[i] = array[left + i];
  }

  for (int j = 0; j < right_size; j++)
  {
    right_array[j] = array[middle + 1 + j];
  }

  int left_i = 0;
  int right_i = 0;
  int i = left;

  // Sort the elements from the left and right arrays
  while (left_i < left_size && right_i < right_size)
  {
    if (left_array[left_i] <= right_array[right_i])
    {
      array[i] = left_array[left_i];
      left_i++;
    }
    else
    {
      array[i] = right_array[right_i];
      right_i++;
    }
    i++;
  }

  // Check if there are remaining elements in the left array
  while (left_i < left_size)
  {
    array[i] = left_array[left_i];
    left_i++;
    i++;
  }

  // Check if there are remaining elements in the right array
  while (right_i < right_size)
  {
    array[i] = right_array[right_i];
    right_i++;
    i++;
  }

  iterations += i;
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