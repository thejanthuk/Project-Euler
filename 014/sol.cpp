#include <iostream>
#include <cstdint>

using i64 = std::int64_t;

constexpr int A = 1000000;

int main()
{
  int max = -1;
  int ans = -1;
  for (int a = 1; a < A; a++) {
    i64 n = a;
    int c = 1;
    while (true) {
      i64 m = n % 2 == 0 ? n / 2 : n * 3 + 1;

      c++;
      if (m == 1)
        break;

      n = m;
    }

    if (max < c) {
      max = c;
      ans = a;
    }
  }

  std::cout << ans << '\n';

  return 0;
}
