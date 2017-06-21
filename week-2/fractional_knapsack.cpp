#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

class SackNode {
  public:
    int weight;
    int value;
    double ratio;

    SackNode(){};
    SackNode(int a, int b) : weight(a), value(b) {
      setRatio();
    }

    void setRatio() {
      ratio = (double)value / weight;
    }
};

void quickSort(vector<SackNode>& A, int p, int q);
int partition(vector<SackNode>& A, int p, int q);

void quickSort(vector<SackNode>& A, int p, int q) {
  int r;

  if(p < q) {
    r = partition(A, p, q);
    quickSort(A, p, r);
    quickSort(A, r+1, q);
  }
}

int partition(vector<SackNode>& A, int p, int q) {
  double x = A[p].ratio;
  int i = p;
  int j;

  for(j = p + 1; j < q; j++) {
    if(A[j].ratio <= x) {
      i=i+1;
      std::swap(A[i],A[j]);
    }
  }

  std::swap(A[i],A[p]);
  return i;
}


double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values) {
  int numOfItems = weights.size();
  if (capacity < 1 || numOfItems < 1)
    return 0;

  vector<SackNode> items;
  double value = 0.0;
  int i, currentValue;


  for (i = 0; i < numOfItems; i++) {
    items.push_back(SackNode(weights[i], values[i]));
  }

  //sort least to greatest
  quickSort(items, 0, numOfItems);

  while(capacity > 0 && items.size() > 0) {
    if (items.back().weight < capacity) {
      value = value + items.back().value;
      capacity = capacity - items.back().weight;
      items.pop_back();
    } else {
      value = value + (items.back().ratio * capacity);
      capacity = 0;
    }
  }

  return value;
}


//int main() {
//  std::setprecision(5);
//
//  SackNode one (10,100);
//  SackNode two (20,100);
//  SackNode three (30,100);
//  SackNode four (40,100);
//
//  vector<SackNode> items = {two, four, one, three};
//
//  quickSort(items, 0, 4);
//
//  for (int i = 0; i < items.size(); i++) {
//    std::cout << items[i].ratio << ", ";
//  }
//
//  return 0;
//}

int main() {
  std::setprecision(5);

  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(5);
  std::cout << std::fixed <<optimal_value << std::endl;
  return 0;
}
