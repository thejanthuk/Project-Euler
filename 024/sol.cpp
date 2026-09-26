#include <iostream>
#include <string>
#include <algorithm>

constexpr int N = 1000000;

int main()
{
  std::string ss = "0123456789";

  int n = N;
  do {
    n--;
  } while (n > 0 && std::next_permutation(ss.begin(), ss.end()));

  std::cout << ss << '\n';

  return 0;
}
