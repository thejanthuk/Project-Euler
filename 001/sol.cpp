#include <iostream>

constexpr int N = 1000;

int main()
{
  int sum = 0;
  for (int i = 1; i < N; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  std::cout << sum << '\n';

  return 0;
}
