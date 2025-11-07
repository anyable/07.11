#include <iostream>
int * extend(const int * a, size_t k, size_t d, int filler);



int *add_row(const int * a, size_t n, size_t m, int filler)
{
  return extend(a, n * m, (n + 1) * m, filler);
}

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

void add_col(int ** a, size_t n, size_t m, int filler)
{
  for (size_t i = 0; i < n; i++)
  {
    int * new_str = extend(a[i], m, m + 1, filler);
    delete [] a[i];
    a[i] = new_str;
  }
}

/*for(size_t i = 0; i < n; i++)
{
  extend(a + i, m, m + 1, filler);
}*/


int * add_col(const int * a, size_t n, size_t m, int filler)
{
  int * new_array = new int[n * (m + 1)];
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; i < m; i++)
    {
      new_array[i * (m + 1) + j] = a[i * m + j]; 
    }
    new_array[i * (m + 1) + m] = filler;
  }
}


int main()
{
  int * array = new int[5]{1, 2, 3, 4, 5};
  int * new_matrix = add_row(array, 2, 2, 0);
  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      std::cout << new_matrix[i * 2 + j] << ' ';
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
