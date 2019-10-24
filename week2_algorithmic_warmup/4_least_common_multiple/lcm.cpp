#include <iostream>

long long lcm_naive(int, int);
long long lcm_divided(int, int);
int gcd(int, int);

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_divided_by_gcd(int a, int b) {
  return (long long) a * b / gcd(a, b);
}

int gcd(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b) a %= b;
    else b %= a;
  }

  return (a == 0) ? b : a;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_divided_by_gcd(a, b) << std::endl;
  return 0;
}
