#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int partition(vector<int>& arr, int startIdx, int endIdx) {
  double pivot = arr[startIdx];
  int i = startIdx;

  int j;
  for(j = startIdx + 1; j < endIdx; j++) {
    if(arr[j] >= pivot) {
      i = i + 1;
      std::swap(arr[i],arr[j]);
    }
  }

  std::swap(arr[i],arr[startIdx]);
  return i;
}

// 0 to number of items
void quicksort(vector<int>& arr, int leftEdge, int rightEdge) {
  int pivot;

  if (leftEdge < rightEdge) {
    pivot = partition(arr, leftEdge, rightEdge);

    quicksort(arr, leftEdge, pivot);
    quicksort(arr, pivot + 1, rightEdge);
  }
}

long long max_dot_product(vector<int> a, vector<int> b, int len) {

  quicksort(a, 0, len);
  quicksort(b, 0, len);
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

// commented out main

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);

  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::cout << max_dot_product(a, b, n) << std::endl;
  return 0;
}


//int main() {
//  vector<int> test = {5,88,3,123,5,89,6,-8};
//  quicksort(test, 0, test.size());
//  std::cout << "-------- Test Begin --------" << "\n";
//  for(int i = 0; i < test.size(); ++i) {
//    std::cout << test[i] << " ";
//  }
//  return 0;
//}
