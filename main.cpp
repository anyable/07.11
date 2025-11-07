#include <iostream>
int * extend(const int * a, size_t k, size_t d, int filler);

void extend(int ** ptr_a, size_t k, size_t d, int filler)
{
  int * new_array = extend(*ptr_a, k, d, filler);
  delete [] *ptr_a;
  *ptr_a = new_array;
}

int * extend(const int * a, size_t k, size_t d, int filler)
{
  int * new_array = new int[d];
  for (size_t i = 0; i < std::min(k, d); i++)
  {
    new_array[i] = a[i];
  }
  for (size_t i = std::min(k, d); i < d; i++)
  {
    new_array[i] = filler;
  }
  return new_array;
}

int main()
{
  int * array = new int[5]{1, 2, 3, 4, 5};
  int **ptr_a = &array;
  extend(ptr_a, 5, 10, 0);
  for (size_t i = 0; i < 10; i++)
  {
    std::cout << array[i];
  }
}
