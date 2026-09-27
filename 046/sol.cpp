#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
#include <bitset>

using i64 = std::int64_t;

constexpr int N = 100000;

int main()
{
  std::bitset<N + 1> composite;
  std::vector<int> pp;

  composite[0] = 1;
  composite[1] = 1;
  pp.push_back(2);
  for (int j = 4; j <= N; j += 2)
    composite[j] = 1;
  for (int i = 3; i <= N; i += 2) {
    if (!composite[i]) {
      pp.push_back(i);

      for (i64 j = i64(i) * i; j <= N; j += i * 2)
        composite[j] = 1;
    }
  }

  int a = 3;
  while (a < N) {
    if (!composite[a]) {
      a += 2;
      continue;
    }

    bool ok = true;
    for (auto p : pp) {
      int x = a - p;
      if (x < 0)
        break;
      if (x % 2)
        continue;
      x /= 2;

      int y = std::sqrt(x) + 1;
      while (y * y > x)
        y--;
      if (y * y == x) {
        ok = false;
        break;
      }
    }
    if (ok) {
      std::cout << a << '\n';
      return 0;
    }

    a += 2;
  }

  return 0;
}
