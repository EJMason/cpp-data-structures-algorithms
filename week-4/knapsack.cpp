#include <iostream>
#include <vector>
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

    for(i; i <= W; i++) {
      newPossibleBest = currentValue + prev->at(i-currentValue);
      prevBest = prev->at(i);

      curr->at(i) = std::max(newPossibleBest, prevBest);
    }
  }
  solution = curr->back();

  temp = NULL;
  curr = NULL;
  prev = NULL;
  delete temp;
  delete curr;
  delete prev;

  return solution;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  std::vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimalGold(W, w) << '\n';
}
