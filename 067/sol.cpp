#include <iostream>
#include <fstream>
#include <vector>

constexpr int N = 100;

int main()
{
  std::ifstream file("triangle.txt");
  std::string line;

  std::vector aa(N, std::vector<int>()), dp(N, std::vector<int>());
  for (int i = 0; i < N; i++) {
    aa[i].resize(i + 1, 0);
    dp[i].resize(i + 1, 0);
  }

  int r = 0;
  while (std::getline(file, line)) {
    int c = 0;

    int m = int(line.size());
    for (int i = 0; i < m; i += 3) {
      int a = (line[i] - '0') * 10 + (line[i + 1] - '0');

      dp[r][c] = a;
      aa[r][c] = a;

      c++;
    }

    r++;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (i != j)
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + aa[i][j]);
      if (j != 0)
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + aa[i][j]);
    }
  }

  int max = 0;
  for (int j = 0; j < N; j++)
    max = std::max(max, dp[N - 1][j]);

  std::cout << max << '\n';

  return 0;
}
