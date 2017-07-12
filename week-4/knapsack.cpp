#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

int optimalGold(int W, const std::vector<int> &values) {
  std::vector<int> *curr = new std::vector<int> (W+1,0);
  std::vector<int> *prev = new std::vector<int> (W+1);
  std::vector<int> *temp;
  int newPossibleBest, prevBest, currentValue, i, solution;

  for(int value_idx = 0; value_idx < values.size(); value_idx++) {
    currentValue = values[value_idx];
    if(currentValue > W) continue;

    temp = curr;
    curr = prev;
    prev = temp;

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


//int main() {
//  int n, W;
//  std::cin >> W >> n;
//  std::vector<int> w(n);
//  for (int i = 0; i < n; i++) {
//    std::cin >> w[i];
//  }
//  std::cout << optimalGold(W, w) << '\n';
//}

// ================================================================================
//                    TESTING
// ================================================================================
//int optimalGold(int W, const std::vector<int> &values) {
//  //first we need to create 2 arrays
//  std::vector<int> *curr = new std::vector<int> (W+1,0);
//  std::vector<int> *prev = new std::vector<int> (W+1);
//  std::vector<int> *temp;
//  int newPossibleBest, prevBest, currentValue, i, solution;
//  //need to iterate all possible weights
//  for(int value_idx = 0; value_idx < values.size(); value_idx++) {
//
//    currentValue = values[value_idx];
//    if(currentValue > W) continue;
//
//    temp = curr;
//    curr = prev;
//    prev = temp;
//
//    std::cout << "---------- " << value_idx << " -------------------" << std::endl;
//    std::cout << "Prev: ";
//    for(int j = 0; j < prev->size(); j++){
//      std::cout << prev->at(j) << " ";
//    }
//    std::cout << "\n";
//
//    std::cout << "Curr: ";
//    for(int j = 0; j < curr->size(); j++){
//      std::cout << curr->at(j) << " ";
//    }
//    std::cout << "\n";
//    std::cout << "-----------------------------" << std::endl;
//
//    i = -1;
//    while(++i < currentValue)
//      (*curr)[i] = prev->at(i);
//
//    std::cout << "GO " << currentValue << std::endl;
//    for(i; i <= W; i++) {
//
//      newPossibleBest = currentValue + prev->at(i-currentValue);
//      prevBest = prev->at(i);
//
//      curr->at(i) = std::max(newPossibleBest, prevBest);
//    }
//
////    std::cout << "Prev: ";
////    for(int j = 0; j < prev->size(); j++){
////      std::cout << prev->at(j) << " ";
////    }
////    std::cout << "\n";
////
////    std::cout << "Curr: ";
////    for(int j = 0; j < curr->size(); j++){
////      std::cout << curr->at(j) << " ";
////    }
////    std::cout << "\n";
//  }
//
//    std::cout << "THIS IS THE END:   " << std::endl;
//    std::cout << "Prev: ";
//    for(int j = 0; j < prev->size(); j++){
//      std::cout << prev->at(j) << " ";
//    }
//    std::cout << "\n";
//
//    std::cout << "Curr: ";
//    for(int j = 0; j < curr->size(); j++){
//      std::cout << curr->at(j) << " ";
//    }
//    std::cout << "\n";
//
//  solution = curr->back();
//
//  temp = NULL;
//  curr = NULL;
//  prev = NULL;
//  delete temp;
//  delete curr;
//  delete prev;
//
//  return solution;
//}

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, std::vector<int> &wt, std::vector<int> &val, int n) {
  int i, w;
  int K[n+1][W+1];

  // Build table K[][] in bottom up manner
  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= W; w++)
    {
      if (i==0 || w==0)
        K[i][w] = 0;
      else if (wt[i-1] <= w)
        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
      else
        K[i][w] = K[i-1][w];
    }
  }

  return K[n][W];
}


void test_solution() {
  int randomBagTotal;
  int randomElementsTotal;
  int mine, greedy;
  std::vector<int> randomElements;

  while (true) {
    randomBagTotal = 100 + (rand() % 500);
    randomElementsTotal = 30 + (rand() % 82);

    std::cout << "Bag Size: " << randomBagTotal << "  Values: " << std::endl;
    std::cout << "[ ";
    for(int i = 0; i <=randomElementsTotal; i++) {
      randomElements.push_back(100 + (rand() % 250));
      std::cout << randomElements.back() << " ";
    }
    std::cout << "]\n" << std::endl;


    mine = optimalGold(randomBagTotal, randomElements);
    greedy = knapSack(randomBagTotal, randomElements, randomElements, randomElementsTotal);

    std::cout << mine << " | " << greedy << std::endl;
    assert(mine == greedy);
    std::cout << std::endl;

    randomElements = std::vector<int>();
  }
}

int main() {
  test_solution();
  return 0;
}
