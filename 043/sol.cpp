#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>

using i64 = std::int64_t;

constexpr int N = 1000000;

int main()
{
  std::string ss = "0123456789";

  i64 sum = 0;
  do {
    int a = std::stoi(ss.substr(1, 3));
    if (a % 2)
      continue;
    a = std::stoi(ss.substr(2, 3));
    if (a % 3)
      continue;
    a = std::stoi(ss.substr(3, 3));
    if (a % 5)
      continue;
    a = std::stoi(ss.substr(4, 3));
    if (a % 7)
      continue;
    a = std::stoi(ss.substr(5, 3));
    if (a % 11)
      continue;
    a = std::stoi(ss.substr(6, 3));
    if (a % 13)
      continue;
    a = std::stoi(ss.substr(7, 3));
    if (a % 17)
      continue;
    sum += std::stoll(ss);
  } while (std::next_permutation(ss.begin(), ss.end()));

  std::cout << sum << '\n';

  return 0;
}
