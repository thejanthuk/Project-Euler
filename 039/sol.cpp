#include <iostream>

constexpr int P = 1000;

int main()
{
  int max = 0;
  int ans = 0;
  for (int p = 1; p <= P; p++) {
    int cnt = 0;
    for (int a = 1; a <= p; a++) {
      for (int b = a + 1; b <= p - a; b++) {
        int c = p - a - b;
        if (!(a < c && b < c))
          break;
        
        int x = a * a;
        int y = b * b;
        int z = c * c;
        if (x + y == z)
          cnt++;
      }
    }

    if (max < cnt) {
      max = cnt;
      ans = p;
    }
  }

  std::cout << ans << '\n';

  return 0;
}
