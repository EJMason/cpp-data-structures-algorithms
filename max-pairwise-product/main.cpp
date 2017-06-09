#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

void swap(int &big, int &small) {
    int temp = big;
    big = small;
    small = temp;
}

long long MaxPairwiseProduct(const vector<int>& numbers) {
    int firstBiggest = 0;
    int secondBiggest = 0;

    int length = numbers.size();

    for (int i = 0; i < length; i++) {
        if (numbers[i] > secondBiggest) {
            secondBiggest = numbers[i];

            if (secondBiggest > firstBiggest) {
                swap(secondBiggest, firstBiggest);
            }
        }
    }
    return (long long)firstBiggest * secondBiggest;
}



int main() {
    // =========== setup / input ========== //
    int n;
    cin >> n;
    vector<int> numbers((unsigned long) n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // =========== invocation ========== //
    long long result = MaxPairwiseProduct(numbers);
    cout << result << std::endl;
    return 0;
}

