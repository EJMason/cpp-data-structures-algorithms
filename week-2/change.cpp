#include <iostream>

int get_change(int m) {
  int n;

  n = m / 10;
  m = m % 10;

  n = n + m / 5;
  m = m % 5;

  n = n + m;

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
