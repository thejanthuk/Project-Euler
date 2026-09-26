#include <iostream>

constexpr int N = 1000;

int main()
{
  for (int a = 1; a <= N; a++) {
    for (int b = a + 1; b <= N - a; b++) {
      int c = N - a - b;
      if (!(a < b && b < c))
        break;

      int x = a * a;
      int y = b * b;
      int z = c * c;

      if (x + y == z) {
        std::cout << a * b * c << '\n';
        return 0;
      }
    }
  }

  return 0;
}
