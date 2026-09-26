#include <iostream>
#include <algorithm>

bool is_prime(int a)
{
  if (a == 1)
    return false;
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0)
      return false;
  return true;
}

bool is_trunable_prime_l(int a)
{
  std::string ss = std::to_string(a);
  while (!ss.empty()) {
    int s = std::stoi(ss);
    if (!is_prime(s))
      return false;

    ss.pop_back();
  }

  return true;
}

bool is_trunable_prime_r(int a)
{
  std::string ss = std::to_string(a);
  while (!ss.empty()) {
    int s = std::stoi(ss);
    if (!is_prime(s))
      return false;

    std::reverse(ss.begin(), ss.end());
    ss.pop_back();
    std::reverse(ss.begin(), ss.end());
  }

  return true;
}

int main()
{
  int sum = 0;
  int cnt = 0;
  int a = 11;
  while (cnt < 11) {
    if (is_trunable_prime_l(a) && is_trunable_prime_r(a)) {
      sum += a;
      cnt += 1;
    }

    a++;
  }

  std::cout << sum << '\n';

  return 0;
}
