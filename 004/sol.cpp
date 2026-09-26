#include <iostream>

bool is_palindrome(int n)
{
  std::string ss = std::to_string(n);
  int m = int(ss.size());

  for (int i = 0; i < m / 2; i++)
    if (ss[i] != ss[m - i - 1])
      return false;
  return true;
}

int main()
{
  int max = -1;
  for (int a = 100; a <= 999; a++) {
    for (int b = a; b <= 999; b++) {
      int c = a * b;
      if (is_palindrome(c))
        max = std::max(max, c);
    }
  }

  std::cout << max << '\n';

  return 0;
}
