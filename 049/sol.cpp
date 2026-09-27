#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>
#include <map>

using i64 = std::int64_t;

constexpr int N = 10000;

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

  for (auto p : pp) {
    if (int(std::to_string(p).size()) < 4)
      continue;
    if (int(std::to_string(p).size()) > 4)
      break;

    int d = 1;
    while (true) {
      std::string aa = std::to_string(p);
      std::string bb = std::to_string(p + d);
      std::string cc = std::to_string(p + d * 2);
      int n = int(aa.size());
      int k = int(cc.size());
      if (n < k)
        break;

      std::map<char, int> xx;
      std::map<char, int> yy;
      std::map<char, int> zz;
      for (auto a : aa)
        xx[a]++;
      for (auto b : bb)
        yy[b]++;
      for (auto c : cc)
        zz[c]++;
      if (xx == yy && xx == zz)
        if (!composite[p] && !composite[p + d] && !composite[p + d * 2])
          std::cout << p << p + d << p + d * 2 << '\n';

      d++;
    }
  }

  return 0;
}
