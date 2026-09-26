#include <iostream>
#include <cstdint>

using i64 = std::int64_t;

int n_divisor(i64 a)
{
  int n = 0;
  for (i64 i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      n++;
      if (a / i != i)
        n++;
    }
  }

  return n;
}

int main()
{
  i64 a = 0;

  int n = 1;
  while (true) {
    a += n;

    if (n_divisor(a) > 500) {
      std::cout << a << '\n';
      break;
    }

    n++;
  }

  return 0;
}
