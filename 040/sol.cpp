#include <iostream>
#include <cstdint>
#include <string>

using i64 = std::int64_t;

int power(int a, int k)
{
  int p = 1;
  while (k) {
    if (k & 1)
      p *= a;

    a *= a;

    k >>= 1;
  }

  return p;
}

int solve(int n)
{
  if (n <= 9)
    return n;

  int b = 9;
  int d = 1;
  while (n > i64(b) + 9 * power(10, d + 1) * (d + 1)) {
    d += 1;
    b += 9 * power(10, d) * d;
  }
  int f = n - b;
  int m = (f - 1) / d;

  int a = power(10, d + 1) + m;
  std::cerr << "(d, a, f): " << d << ' ' << a << ' ' << f << std::endl;

  auto ss = std::to_string(a);

  return ss[(f - 1) % (d + 1)] - '0';
}

int main()
{
  int ans = 1;
  for (int k = 0; k <= 6; k++) {
//    std::cout << "(k): " << solve(power(10, k)) << '\n';
    ans *= solve(power(10, k));
  }

  std::cout << ans << '\n';

  return 0;
}
