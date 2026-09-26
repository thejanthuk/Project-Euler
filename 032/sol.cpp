#include <iostream>
#include <bitset>
#include <vector>

constexpr int A = 10;
constexpr int N = 10000;

int main()
{
  std::bitset<N * N> used;
  for (int a = 1; a < N; a++) {
    for (int b = a; b < N; b++) {
      int c = a * b;

      std::string aa = std::to_string(a);
      std::string bb = std::to_string(b);
      std::string cc = std::to_string(c);
      std::vector<int> cnt(A);
      for (auto x : aa)
        cnt[x - '0']++;
      for (auto x : bb)
        cnt[x - '0']++;
      for (auto x : cc)
        cnt[x - '0']++;

      bool ok = cnt[0] == 0;
      for (int x = 1; x < A; x++) {
        if (cnt[x] != 1) {
          ok = false;
          break;
        }
      }

      if (ok)
        used[c] = 1;
    }
  }

  int sum = 0;
  for (int x = 1; x < N * N; x++)
    if (used[x])
      sum += x;

  std::cout << sum << '\n';

  return 0;
}
