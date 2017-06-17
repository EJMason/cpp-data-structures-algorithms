#include <iostream>

// #include <cassert>
// #include <stdlib.h>

int gcd_better(int a, int b);

// int gcd_naive(int a, int b);
// void test_solution();


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_better(a, b) << std::endl;

  return 0;
}

/*
constraints
a,b >= 1
a,b <= 2 * 10^9 (int ok)
*/
int gcd_better(int a, int b) {
  int temp;
  while (b != 0) {
    temp = a;
    a = b;
    b = temp % a;
  }
  return a;
}

// =============================================
//              Test Suite
// =============================================

// int gcd_naive(int a, int b) {
//   int current_gcd = 1;
//   for (int d = 2; d <= a && d <= b; d++) {
//     if (a % d == 0 && b % d == 0) {
//       if (d > current_gcd) {
//         current_gcd = d;
//       }
//     }
//   }
//   return current_gcd;
// }

// void test_solution() {
//     int randa;
//     int randb;
//     int a;
//     int b;
//     for (int n = 0; n < 200; ++n) {
//         randa = rand() % 1500000;
//         randb = rand() % 1500000;
//         a = gcd_better(randa, randb);
//         b = gcd_naive(randa, randb);
//         std::cout << "answer: " << a << "    " << b << std::endl;
//         assert(a == b);
//     }
// }
