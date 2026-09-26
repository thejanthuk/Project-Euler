#include <iostream>
#include <vector>
#include <bitset>

constexpr int N = 28123;

bool is_perfect(int a)
{
  int sum = 0;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      if (i != a)
        sum += i;
      if (a / i != i && a / i != a)
        sum += a / i;
    }
  }

  return sum > a;
}

int main()
{
  std::vector<int> aa;
  for (int a = 1; a <= N; a++)
    if (is_perfect(a))
      aa.push_back(a);

  int n = int(aa.size());

  std::bitset<N + 1> dp;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      if (aa[i] + aa[j] <= N)
        dp[aa[i] + aa[j]] = 1;
  
  int sum = 0;
  for (int a = 1; a <= N; a++)
    if (!dp[a])
      sum += a;
  std::cout << sum << '\n';

  return 0;
}
