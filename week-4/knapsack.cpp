#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


int optimal_weight(int W, const std::vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int weight(int W, std::vector<int> &m) {

  int current_weight = 0;
  int temp;
  for (int i = 0; i < m.size(); i++) {
    for (int j = i + 1; j < m.size(); j++) {
      if (m[i] < m[j]) {
        temp = m[j];
        m[j] = m[i];
        m[i] = temp;
      }
    }
  }

  for (size_t i = 0; i < m.size(); ++i) {

    if (current_weight + m[i] <= W) {
      current_weight += m[i];
    }
  }
  return current_weight;
}

int optimalGold(int W, const std::vector<int> &values) {
  //first we need to create 2 arrays
  std::vector<int> *curr = new std::vector<int> (W+1,0);
  std::vector<int> *prev = new std::vector<int> (W+1);
  std::vector<int> *temp;
  int newPossibleBest, prevBest, currentValue, i, solution;
  //need to iterate all possible weights
  for(int value_idx = 0; value_idx < values.size(); value_idx++) {
    temp = curr;
    curr = prev;
    prev = temp;

    currentValue = values[value_idx];
    if(currentValue > W) continue;

    i = -1;
    while(++i < currentValue)
      (*curr)[i] = prev->at(i);

    std::cout << "GO " << currentValue << std::endl;
    for(i; i <= W; i++) {

      newPossibleBest = currentValue + prev->at(i-currentValue);
      prevBest = prev->at(i);

      curr->at(i) = std::max(newPossibleBest, prevBest);
    }

    std::cout << "Prev: ";
    for(int j = 0; j < prev->size(); j++){
      std::cout << prev->at(j) << " ";
    }
    std::cout << "\n";

    std::cout << "Curr: ";
    for(int j = 0; j < curr->size(); j++){
      std::cout << curr->at(j) << " ";
    }
    std::cout << "\n";
  }

  solution = prev->back();

  temp = NULL;
  curr = NULL;
  prev = NULL;
  delete temp;
  delete curr;
  delete prev;

  return solution;
}

//void test_solution() {
//  int randomBagTotal;
//  int randomElementsTotal;
//  int mine, greedy;
//  std::vector<int> randomElements;
//
//  while (true) {
//    randomBagTotal = 1 + (rand() % 50);
//    randomElementsTotal = 3 + (rand() % 8);
//
//    std::cout << "Bag Size: " << randomBagTotal << "  Values: " << std::endl;
//    std::cout << "[ ";
//    for(int i = 0; i <=randomElementsTotal; i++) {
//      randomElements.push_back(1 + (rand() % 30));
//      std::cout << randomElements.back() << " ";
//    }
//    std::cout << "]\n" << std::endl;
//
//
//    mine = optimalGold(randomBagTotal, randomElements);
//    greedy = weight(randomBagTotal, randomElements);
//
//    std::cout << mine << " | " << greedy << std::endl;
//    assert(mine == greedy);
//    std::cout << std::endl;
//
//    randomElements = std::vector<int>();
//  }
//}

//int main() {
//  int n, W;
//  std::cin >> W >> n;
//  std::vector<int> w(n);
//  for (int i = 0; i < n; i++) {
//    std::cin >> w[i];
//  }
//  std::cout << optimalGold(W, w) << '\n';
//}

int main() {
  test_solution();
  return 0;
}
