#include <iostream>

constexpr int N = 1000;

bool is_prime(int a)
{
  if (a <= 0)
    return false;
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0)
      return false;
  return true;
}

int brute(int a, int b)
{
  int n = -1;
  while (true) {
    int m = n + 1;
    if (!is_prime(m * m + a * m + b))
      break;

    n++;
  }

  return n;
}

int main()
{
  int max = -1;
  int x = -1;
  int y = -1;
  for (int a = -N + 1; a < N; a++) {
    for (int b = -N; b <= N; b++) {
      int cur = brute(a, b);
      if (max < cur) {
        max = cur;
        x = a;
        y = b;
      }
    }
  }

  std::cout << x * y << '\n';

  return 0;
}
