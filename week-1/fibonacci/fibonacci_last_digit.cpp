#include <iostream>
#include <cassert>

int get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;

    int numbers [2];

    numbers[0] = 0;
    numbers[1] = 1;

    for (int i = 2; i <= n; ++i) {
        numbers[i % 2] = (numbers[0] + numbers[1]) % 10;
    }

    return numbers[n % 2];
}

// int fibonacci_naive(int n) {
//     if (n <= 1)
//         return n;

//     return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
// }

// void test_solution() {
//     int a;
//     int b;
//     for (int n = 0; n < 20; ++n) {
//         a = get_fibonacci_last_digit(n);
//         b = fibonacci_naive(n) % 10;
//         std::cout << "answer: " << a << "    " << b << std::endl;
//         assert(a == b);
//     }
// }

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    // test_solution();
}

