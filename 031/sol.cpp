#include <iostream>
#include <vector>

constexpr int N = 200;

int main()
{
  std::vector<int> dp(N + 1);
  dp[0] = 1;
  for (auto p : {1, 2, 5, 10, 20, 50, 100, 200}) {
    for (int i = 0; i <= N; i++) {
      if (i + p > N)
        break;
      dp[i + p] += dp[i];
    }
  }

  std::cout << dp[N] << '\n';

  return 0;
}
