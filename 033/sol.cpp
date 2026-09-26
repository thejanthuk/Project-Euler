#include <iostream>
#include <utility>
#include <numeric>

constexpr int N = 100;

std::pair<int, int> fraction(int a, int b)
{
  int d = std::gcd(a, b);

  return {a / d, b / d};
}

int main()
{
  int top = 1;
  int bot = 1;
  for (int a = 10; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      auto x = fraction(a, b);

      std::string aa = std::to_string(a);
      std::string bb = std::to_string(b);

      bool cancel = false;
      if (aa[0] == bb[0]) {
        cancel = aa[0] != '0';
        aa.erase(aa.begin());
        bb.erase(bb.begin());
      }
      else if (aa[0] == bb[1]) {
        cancel = aa[0] != '0';
        aa.erase(aa.begin());
        bb.pop_back();
      }
      else if (aa[1] == bb[0]) {
        cancel = aa[1] != '0';
        aa.pop_back();
        bb.erase(bb.begin());
      }
      else if (aa[1] == bb[1]) {
        cancel = aa[1] != '0';
        aa.pop_back();
        bb.pop_back();
      }

      if (!cancel)
        continue;

      auto y = fraction(std::stoi(aa), std::stoi(bb));

      if (x == y) {
        top *= a;
        bot *= b;
      }
    }
  }

  auto z = fraction(top, bot);

  std::cout << z.second << '\n';

  return 0;
}
