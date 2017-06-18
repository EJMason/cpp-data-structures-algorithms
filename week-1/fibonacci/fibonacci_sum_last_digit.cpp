#include <iostream>

//int fibonacci_sum_naive(long long n) {
//    if (n <= 1)
//        return n;
//
//    long long previous = 0;
//    long long current  = 1;
//    long long sum      = 1;
//
//    for (long long i = 0; i < n - 1; ++i) {
//        long long tmp_previous = previous;
//        previous = current;
//        current = tmp_previous + current;
//        sum += current;
//    }
//
//    return sum % 10;
//}

int fibSum(long long n) {
    if(n < 3)
        return (int)n;

    int a = 1;
    int b = 2;
    int temp;
    for(int i = 3; i <=n; i++) {
        temp = (a + b + 1) % 10;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibSum(n);
    return 0;
}


