#include <iostream>
#include <cstdint>

using i64 = std::int64_t;

constexpr int N = 1001;

int main()
{
  const int n = (N + 1) / 2;

  i64 sum = 0;
  for (i64 i = 1; i <= n; i++)
    sum += i64(4) * (1 + (i - 1) * (4 * i - 3));

  std::cout << sum - 3 << '\n';

  return 0;
}
