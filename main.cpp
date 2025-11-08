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

// n - колво строк, m - колво столбцов
int * add_col(const int * a, size_t n, size_t m, int filler)
{
  int * new_array = new int[n * (m + 1)];
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      new_array[i * (m + 1) + j] = a[i * m + j]; 
    }
    new_array[i * (m + 1) + m] = filler;
  }
  return new_array;
}

int * transport(const int * a, size_t n, size_t m)
{
  int * new_arr = new int[n * m];
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      new_arr[i * n + j] = a[j * m + i];
    }
  }
  return new_arr;
}

void transpose(int * a, size_t n, size_t m)
{
  int * matrix = transport(a, n, m);
  for (size_t i = 0; i < n*m; ++i)
  {
    a[i] = matrix[i];
  }
  delete [] matrix;
}

int * concat_rows(const int * a, size_t n, size_t m1, const int * b, size_t m2)
{
  
  int * new_arr = new int[n * (m1 + m2)];
  for (size_t i = 0; i < n; ++i)
  {
    for(size_t j = 0; j < (m1 + m2); ++j)
    {
      while (j < m1)
      {
        new_arr[i * (m1 + m2) + j] = a[i * m1 + j];
        j++;
      }
      int start = 0;
      while (j < (m1 + m2))
      {
        new_arr[i * (m1 + m2) + j] = b[i * m2 + start];
        start++;
        j++;
      }
    }
  }
  return new_arr;
}

int * concat_cols(const int * a, size_t n1, size_t m, const int * b, size_t n2)
{
  int * new_arr = extend(a, n1 * m, (n2 + n1) * m, 0);
  size_t start = 0; 
  for (size_t i = n1; i < (n1 + n2); ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      new_arr[i * m + j] = b[start * m + j]; 
    }
    start++;
  }
  return new_arr;
}


void print(int * arr, size_t n, size_t m)
{
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      std::cout << arr[i * m + j] << ' ';
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for (size_t i = 0; i < n * m; ++i)
  {
    std::cout << arr[i] << " ";
  }
}

void add_col(int ** a, size_t n, size_t m, int filler)
{
  for (size_t i = 0; i < n; ++i)
  {
    int * t = a[i];
    a[i] = extend(a[i], m, m + 1, filler);
    delete[] t;
  }
}


int main()
{
  
}
