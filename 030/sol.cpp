#include <iostream>

constexpr int A = 1000000;

int main()
{
  int sum = 0;
  for (int a = 10; a <= A; a++) {
    int n = a;
    int s = 0;
    while (n) {
      int d = n % 10;

      s += d * d * d * d * d;

      n /= 10;
    }

    if (a == s)
      sum += a;
  }

  std::cout << sum << '\n';

  return 0;
}
