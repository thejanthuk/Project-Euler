#include <iostream>

constexpr int N = 10000;

int n_divisor(int a)
{
  int sum = 0;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      if (i != a)
        sum += i;
      if (a / i != i && a / i != a)
        sum += a / i;
    }
  }

  return sum;
}

int main()
{
  int sum = 0;
  for (int a = 1; a < N; a++) {
    int b = n_divisor(a);
    if (n_divisor(b) == a && a != b)
      sum += a;
  }

  std::cout << sum << '\n';

  return 0;
}
