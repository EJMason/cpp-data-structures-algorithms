#include <iostream>
// #include <cassert>


long long findPisano(long long m);
long long fibHugeMod(long long n, long long m);
//long long get_fibonacci_huge_naive(long long n, long long m);
//void testRuntime(long long num);
//void test_solution();

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibHugeMod(n, m) << '\n';
    return 0;
}

// =======================================================================
//                Start Implementation
// =======================================================================

long long fibHugeMod(long long n, long long m) {
    long long min = n % findPisano(m);

    if (min < 2)
        return min;

    long long a = 0;
    long long b = 1;
    long long temp;

    for(int i = 2; i <= min; i++) {       // 3
        temp = (a + b) % m; // p: 4  // temp: 2
        a = b;                            // a: 1
        b = temp;                         // b: 2
    }
    return b;
}

long long findPisano(long long m) {
    // get the length of the pisano sequence
    // at most, longest period is m * m
    long long first = 0;
    long long second = 1;
    long long mod;
    bool found = false;
    int i = 1;
    long long max = m * m;

    while(!found && i < max) {
        mod = (first + second) % m;
        first = second;
        second = mod;

        if(first == 0 && second == 1) {
            found = true;
        }
        i++;
    }
    return i - 1;
}

// --------- Testing --------- //

// void test_solution() {
//     long long randa;
//     long long randb;
//     long long a;
//     long long b;
//     for (int n = 0; n < 10; ++n) {
//         randa = rand() % 46;
//         randb = rand() % 5;
////         randa = 53;
////         randb = 6;
//         a = fibHugeMod(randa, randb);
//         b = get_fibonacci_huge_naive(randa, randb);
//
//         std::cout << "Testing for Fib: " << randa << std::endl;
//         std::cout << "Testing for mod: " << randb << "\n" << std::endl;
//
//         std::cout << "answer: " << a << "    " << b << std::endl;
//         std::cout << "======================" << std::endl;
//         assert(a == b);
//     }
// }


//long long get_fibonacci_huge_naive(long long n, long long m) {
//    if (n <= 1)
//        return n;
//
//    long long previous = 0;
//    long long current  = 1;
//
//    for (long long i = 0; i < n - 1; ++i) {
//        long long tmp_previous = previous;
//        previous = current;
//        current = tmp_previous + current;
//    }
//
//    return current % m;
//}