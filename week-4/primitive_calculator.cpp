#include <iostream>
#include <vector>
#include <algorithm>

//std::vector<int> optimal_sequence(int n) {
//  std::vector<int> sequence;
//  while (n >= 1) {
//    sequence.push_back(n);
//    if (n % 3 == 0) {
//      n /= 3;
//    } else if (n % 2 == 0) {
//      n /= 2;
//    } else {
//      n = n - 1;
//    }
//  }
//  reverse(sequence.begin(), sequence.end());
//  return sequence;
//}

std::vector<int> findMinNumOfOperations(int n) {
  std::vector<int> sequence = {0,0,1,1};
  if(n < 4) return sequence;

  int threes{1};
  int twos{1};
  int ones{0};
  int minNumofOperations;

  for(int i = 4; i <= n; i++) {
    threes++;
    twos++;
    ones = sequence[i-1] + 1;

    if(i % 3 == 0) {
      threes = sequence[i / 3] + 1;
    }

    if(i % 2 == 0) {
      twos = sequence[i / 2] + 1;
    }

    minNumofOperations = std::min(ones, std::min(twos, threes));

    sequence.push_back(minNumofOperations);
  }

  return sequence;
}

std::vector<int> buildSequence(std::vector<int> &seq, int n) {
  if(n < 2) {
    std::vector<int> small = {1};
    return small;
  }
  int numOfOperations = seq.back() + 1; // 14
  std::vector<int> finalSequence(numOfOperations);

  finalSequence[0] = 1;
  finalSequence[numOfOperations - 1] = n;

  for(int i = numOfOperations - 2; i > 0; i--){ //12
    if(finalSequence[i+1] % 3 == 0 && seq[finalSequence[i+1] / 3] == i) {
      finalSequence[i] = finalSequence[i+1] / 3;
    } else if(finalSequence[i+1] % 2 == 0 && seq[finalSequence[i+1] / 2] == i) {
      finalSequence[i] = finalSequence[i+1] / 2;
    } else {
      finalSequence[i] = finalSequence[i+1] - 1;
    }
  }

  return finalSequence;
}

std::vector<int> optimal_sequence(int n) {
  std::vector<int> pre = findMinNumOfOperations(n);
  return buildSequence(pre, n);
}

//int main() {
//  int n;
//  std::cin >> n;
//
//  std::vector<int> seq = optimal_sequence(n);
//  std::vector<int> seq2 = buildSequence(seq, n);
//
//}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
