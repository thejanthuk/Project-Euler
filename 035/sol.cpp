#include <iostream>

constexpr int N = 1000000;

bool is_prime(int a)
{
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0)
      return false;
  return true;
}

bool is_circular_prime(int a)
{
  std::string ss = std::to_string(a);
  int n = int(ss.size());
  for (int r = 0; r < n; r++) {
    int s = std::stoi(ss);
    if (!is_prime(s))
      return false;

    char c = ss[0];
    ss.erase(ss.begin());
    ss.push_back(c);
  }
  return true;
}

int main()
{
  int cnt = 0;
  for (int a = 2; a < N; a++)
    if (is_circular_prime(a))
      cnt++;

  std::cout << cnt << '\n';

  return 0;
}
