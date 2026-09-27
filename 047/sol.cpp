#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>

using i64 = std::int64_t;

constexpr int N = 1000000;

std::bitset<N + 1> composite;
std::vector<int> pp;

int factor(int a)
{
  int cnt = 0;
  for (auto p : pp) {
    if (i64(p) * p > a)
      break;

    bool ok = false;
    while (a % p == 0) {
      if (!ok) {
        ok = true;
        cnt++;
      }

      a /= p;
    }
  }
  if (a > 1)
    cnt++;

  return cnt;
}

int main()
{
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

  int a = 645;
  while (a + 3 < N) {
    int w = a;
    int x = a + 1;
    int y = a + 2;
    int z = a + 3;
    if (factor(w) == 4 && factor(x) == 4 && factor(y) == 4 && factor(z) == 4) {
      std::cout << a << '\n';
      break;
    }

    a++;
  }

  return 0;
}
