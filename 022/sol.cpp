#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
  std::ifstream file("names.txt");
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
  std::sort(ss.begin(), ss.end());

  int sum = 0;
  for (int i = 0; i < int(ss.size()); i++) {
    int cur = 0;

    int m = int(ss[i].size());
    for (int j = 0; j < m; j++) {
      int c = ss[i][j] - 'A' + 1;
      cur += c;
    }

    cur *= i + 1;

    sum += cur;
  }

  std::cout << sum << '\n';

  return 0;
}
