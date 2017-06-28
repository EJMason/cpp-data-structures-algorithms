#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &arr, int numToFind) {
  int left = 0;
  int right = ((int)arr.size()) - 1;
  int mid = 0;

  while(left != right) {
    mid = left + (right - left)/2;

    if(arr[mid] == numToFind)
      return mid;

    if(arr[mid] < numToFind)
      left = mid+1;
    else
      right = mid;
  }
  return (arr[left] == numToFind) ? left : -1;
}

int binary_search_better(const std::vector<int> &arr, int num) {
  int left = 0;
  int right = ((int)arr.size()) - 1;
  int mid = 0;

  while (left <= right) {
    mid = left + (right - left) / 2;

    if (arr[mid] == num)
      return mid;

    if (arr[mid] < num) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

//int linear_search(const std::vector<int> &a, int x) {
//  for (size_t i = 0; i < a.size(); ++i) {
//    if (a[i] == x)
//        return (int)i;
//  }
//  return -1;
//}

// here is the main for the answer
int main() {

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
    std::cin >> a[i];

  int m;
  std::cin >> m;

  std::vector<int> b(m);
  for (int i = 0; i < m; ++i)
    std::cin >> b[i];

  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
  std::cout << std::endl;
  std::cout << "----" << std::endl;
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search_better(a, b[i]) << ' ';
  }
}

