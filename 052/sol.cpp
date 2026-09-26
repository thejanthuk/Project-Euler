#include <iostream>
#include <cstdint>
#include <map>

using i64 = std::int64_t;

std::map<char, int> count(int a)
{
  std::map<char, int> cc;

  std::string ss = std::to_string(a);
  for (auto s : ss)
    cc[s]++;

  return cc;
}

int main()
{
  int x = 1;
  while (true) {
    auto a = count(x);
    auto b = count(x * 2);
    auto c = count(x * 3);
    auto d = count(x * 4);
    auto e = count(x * 5);
    auto f = count(x * 6);

    if (a == b && a == c && a == d && a == e && a == f) {
      std::cout << x << '\n';
      return 0;
    }

    x++;
  }

  return 0;
}
