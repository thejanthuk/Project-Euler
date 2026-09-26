#include <iostream>
#include <cstdint>

using i64 = std::int64_t;

constexpr i64 N = 600851475143;

bool is_prime(i64 n)
{
  for (i64 i = 2; i * i < n; i++)
    if (n % i == 0)
      return false;
  return true;
}

int main()
{
  i64 max = -1;
  for (i64 i = 1; i * i < N; i++) {
    if (N % i == 0) {
      if (is_prime(i))
        max = std::max(max, i);
      if (is_prime(N / i))
        max = std::max(max, N / i);
    }
  }

  std::cout << max << '\n';

  return 0;
}
