#include <iostream>
#include <vector>

int main() {
  std::vector<int> *prev = new std::vector<int> (10,0);
  std::vector<int> *prev2 = new std::vector<int> (10,0);
  (*prev)[2] = 5;
  prev->at(3) = 599;
  (*prev2)[2] = 666;

//  int a = -1;
//
//  while(++a < 10) {
//    std::cout << a << " ";
//    std::cout << " :D ";
//  }

  std::cout << "\nCheck it --> " << prev->at(3) << std::endl;
  return 0;
}