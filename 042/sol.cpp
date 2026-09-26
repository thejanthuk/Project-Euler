#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

constexpr int N = 20;

int main()
{
  std::ifstream file("words.txt");
  std::string line;

  std::vector<std::string> ss;
  while (std::getline(file, line)) {
    int n = int(line.size());
    for (int i = 0; i < n; i++) {
      if (line[i] == '"') {
        int j = i;
        while (j + 1 < n && line[j + 1] != '"')
          j++;

        std::string s;
        s.reserve(j - i + 1);
        for (int p = i + 1; p <= j; p++)
          s.push_back(line[p]);
        
        ss.push_back(s);

        i = j + 1;
      }
    }
  }

  std::vector<int> tt(N + 1);
  for (int i = 1; i <= N; i++)
    tt[i] = i * (i + 1) / 2;

  int cnt = 0;
  for (int i = 0; i < int(ss.size()); i++) {
    int cur = 0;

    int m = int(ss[i].size());
    for (int j = 0; j < m; j++) {
      int c = ss[i][j] - 'A' + 1;
      cur += c;
    }

    if (std::binary_search(tt.begin(), tt.end(), cur))
      cnt++;
  }

  std::cout << cnt << '\n';

  return 0;
}
