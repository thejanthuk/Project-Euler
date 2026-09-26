#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

constexpr int N = 20;
constexpr int K = 4;

const std::vector<std::pair<int, int>> dd = {{0, -1}, {-1, 0}, {0, 1},
                                             {1, 0}, {-1, -1}, {1, 1},
                                             {-1, 1}, {1, -1}};

int main()
{
  std::ifstream file("grid.txt");
  std::string line;

  std::vector aa(N, std::vector<int>(N));
  int r = 0;
  while (std::getline(file, line)) {
    int c = 0;

    int m = int(line.size());
    for (int i = 0; i < m; i += 3) {
      int a = (line[i] - '0') * 10 + (line[i + 1] - '0');

      aa[r][c++] = a;
    }

    r++;
  }
  file.close();

  int max = 0;
  for (int i = K - 1; i < N - K + 1; i++) {
    for (int j = K - 1; j < N - K + 1; j++) {
      for (auto [di, dj] : dd) {
        int a = 1;
        for (int k = 0; k < K; k++)
          a *= aa[i + k * di][j + k * dj];

        max = std::max(max, a);
      }
    }
  }

  std::cout << max << '\n';

  return 0;
}
