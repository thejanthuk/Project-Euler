#include <iostream>

constexpr int A = 1000000;

bool is_palindrome_2(int a)
{
  std::string ss;

  int x = a;
  while (x) {
    ss.push_back(char('0' + x % 2));

    x >>= 1;
  }

  int n = int(ss.size());

  for (int i = 0; i < n / 2; i++)
    if (ss[i] != ss[n - i - 1])
      return false;
  return true;
}

bool is_palindrome_10(int a)
{
  std::string ss = std::to_string(a);
  int n = int(ss.size());

  for (int i = 0; i < n / 2; i++)
    if (ss[i] != ss[n - i - 1])
      return false;
  return true;
}

bool is_palindrome(int a)
{
  return is_palindrome_10(a) && is_palindrome_2(a);
}

int main()
{
  int sum = 0;
  for (int a = 1; a < A; a++)
    if (is_palindrome(a))
      sum += a;

  std::cout << sum << '\n';

  return 0;
}
