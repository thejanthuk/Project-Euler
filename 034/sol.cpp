#include <iostream>
#include <string>
#include <vector>

constexpr int A = 10;
constexpr int T = 1000000;

int main()
{
  std::vector<int> ff(A);
  ff[0] = 1;
  for (int a = 1; a < A; a++)
    ff[a] = ff[a - 1] * a;

  int a = 10;
  int t = T;
  int ans = 0;
  while (t) {
    std::string ss = std::to_string(a);

    int sum = 0;
    for (auto s : ss)
      sum += ff[s - '0'];

    if (sum == a) {
      ans += a;
      t = T;
    }
    else {
      t--;
    }
    a++;
  }
  std::cerr << "(a): " << a << '\n';

  std::cout << ans << '\n';

  return 0;
}
