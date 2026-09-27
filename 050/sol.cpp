#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>

using i64 = std::int64_t;

constexpr int N = 1000000;

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
  int n = int(pp.size());

  int max = -1;
  i64 ans = -1;
  for (int i = 0; i < n; i++) {
    i64 cur = 0;
    for (int j = i; j < n; j++) {
      cur += pp[j];

      if (cur >= N)
        break;
      if (!composite[cur]) {
        if (max < j - i + 1) {
          max = j - i + 1;
          ans = cur;
        }
      }
    }
  }

  std::cout << ans << '\n';

  return 0;
}
