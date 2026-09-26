#include <iostream>
#include <numeric>

constexpr int N = 20;

int main()
{
  int ans = 1;
  for (int i = 1; i <= N; i++) {
    ans = std::lcm(ans, i);
  }

  std::cout << ans << '\n';

  return 0;
}
