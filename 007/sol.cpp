#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>

using i64 = std::int64_t;

constexpr int N = 10001;
constexpr int A = 250000;

int main()
{
  std::bitset<A + 1> composite;
  std::vector<int> pp;

  pp.push_back(2);
  for (int i = 2 * 2; i <= A; i += 2)
    composite[i] = 1;

  for (int i = 3; i <= A; i += 2) {
    if (!composite[i]) {
      pp.push_back(i);

      for (i64 j = i64(i) * i; j <= A; j += i * 2)
        composite[j] = 1;
    }
  }

//  std::cerr << int(pp.size()) << '\n';
  if (int(pp.size()) >= N)
    std::cout << pp[N - 1] << '\n';

  return 0;
}
