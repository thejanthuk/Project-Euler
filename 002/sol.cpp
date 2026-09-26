#include <iostream>

constexpr int N = 4000000;

int main()
{
  int prev = 1;
  int cur  = 2;

  int sum = cur;
  while (true) {
    int next = prev + cur;
    if (next > N)
      break;
    if (next % 2 == 0)
      sum += next;

    prev = cur;
    cur = next;
  }

  std::cout << sum << '\n';

  return 0;
}
