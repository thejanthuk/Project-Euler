#include <iostream>
#include <cstdint>
#include <cmath>

using i64 = std::int64_t;

int main()
{
  i64 m = 166;
  while (true) {
    i64 p = m * (m * 3 - 1);

    i64 n = std::floor(std::sqrt(p));
    if (n * (n + 1) == p && (n + 1) % 2 == 0) {
      std::cout << p / 2 << '\n';
      return 0;
    }

    m++;
  }

  return 0;
}
