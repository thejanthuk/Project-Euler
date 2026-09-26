#include <iostream>
#include <vector>

constexpr int N = 1000;

const std::vector<int> aa = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
const std::vector<int> bb = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
const std::vector<int> cc = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

int main()
{
  int sum = 0;
  for (int i = 1; i < N; i++) {
    int x = i / 100;
    int y = (i / 10) % 10;
    int z = i % 10;

    if (x > 0)
      sum += aa[x] + (y > 0 || z > 0 ? 10 : 7);
    if (y == 1)
      sum += bb[z];
    else
      sum += cc[y] + aa[z];
  }
  sum += 11;

  std::cout << sum << '\n';

  return 0;
}
