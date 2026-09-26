#include <iostream>
#include <cstdint>
#include <algorithm>

using i64 = std::int64_t;

bool is_prime(i64 a)
{
  for (i64 i = 2; i * i <= a; i++)
    if (a % i == 0)
      return false;
  return true;
}

int main()
{
  i64 max = -1;
  for (int n = 1; n <= 9; n++) {
    std::string aa;
    aa.reserve(n);
    for (int a = 1; a <= n; a++)
      aa.push_back(char('0' + a));

    do {
      i64 a = std::stoll(aa);

      if (is_prime(a))
        max = std::max(max, a);
    } while (std::next_permutation(aa.begin(), aa.end()));
  }

  std::cout << max << '\n';

  return 0;
}
