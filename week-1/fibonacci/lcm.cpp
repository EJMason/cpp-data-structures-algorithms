#include <iostream>

 #include <cassert>

long long lcmOptimized(int a, int b);
long long gcd(int a, int b);
// ----- Testing ----- //
long long lcmNaive(int a, int b);
void test_solution();

// ------ MAIN ------ //
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcmOptimized(a, b) << std::endl;

//  test_solution();
  return 0;
}

long long lcmOptimized(int a, int b) {
  long long product = (long long) a * b;
  long long commonDenom = gcd(a,b);
  return (product / commonDenom);
}

// ------ Help ------ //
long long gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, (a % b));
}

// ------ Testing ------ //
 void test_solution() {
     int randa;
     int randb;
     long long a;
     long long b;
     for (int n = 0; n < 200; ++n) {
         randa = rand() % 5000;
         randb = rand() % 5000;
         a = lcmOptimized(randa, randb);
         b = lcmNaive(randa, randb);
         std::cout << "answer: " << a << "    " << b << std::endl;
         assert(a == b);
     }
 }

long long lcmNaive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}