#include <stdio.h>

int array_size = 300;

void linearsearch(int number_to_find, int numbers[]);
void binarysearch(int number_to_find, int numbers[]);

void seed_array(int array[]);

int main(void)
{
  int numbers[array_size];
  int number_to_find;
  seed_array(numbers);
  printf("Input a value between 1 and %i: ", array_size);
  scanf("%i", &number_to_find);
  linearsearch(number_to_find, numbers);
  binarysearch(number_to_find, numbers);
  return 0;
}

void seed_array(int array[])
{
  for (int i = 0; i < array_size; i++)
  {
    array[i] = i + 1;
  }
}

void binarysearch(int number_to_find, int values[])
{
  int index_found = -1;
  int start_index = 0;
  int end_index = array_size - 1;
  int tries = 0;

  while (index_found == -1 && end_index >= start_index)
  {
    int mid = (start_index + end_index) / 2;
    tries++;
    if (number_to_find == values[mid])
    {
      index_found = mid;
    }
    else if (number_to_find > values[mid])
    {
      start_index = mid + 1;
    }
    else
    {
      end_index = mid - 1;
    }
  }

  if (index_found == -1)
  {
    printf("Value not found in binary search\n");
  }
  else
  {
    printf("The binary search found the value at index %i and took %i tries\n", index_found, tries);
  }
}

void linearsearch(int value_to_find, int values[])
{
  int tries = 0;
  int index_found = -1;
  for (int i = 0; i < array_size; i++)
  {
    tries++;
    if (values[i] == value_to_find)
    {
      index_found = i;
      break;
    }
  }
  if (index_found == -1)
  {
    printf("Value not found in linear search\n");
  }
  else
  {
    printf("The linear search found the value at index %i and took %i tries\n", index_found, tries);
  }
}