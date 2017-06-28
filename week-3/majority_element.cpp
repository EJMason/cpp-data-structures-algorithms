#include <algorithm>
#include <iostream>
#include <vector>

int get_majority_element(std::vector<int> &a, int left, int right);
int prune(std::vector<int> &arr);

int main() {
//  int n;
//  std::cin >> n;
//  std::vector<int> a(n);
//  for (size_t i = 0; i < a.size(); ++i) {
//    std::cin >> a[i];
//  }

//  int maj = get_majority_element(a, 0, (a.size() - 1));
  int maj = prune(a);
  std::cout << maj << '\n';
//  std::cout << (maj != -1) << '\n';
}

int linear_majority_element(std::vector<int> &a) {

}

int prune(std::vector<int> &arr) {
  int len = arr.size();
//  std::cout << "The size is " << len << std::endl;
  if (len == 0) return -1;
  if (len == 1) return arr[0];

  if (len % 2 == 1) {
//    std::cout << "It is odd length  " << len << std::endl;
    int count = 1;
    int target = len / 2 + 1;
    int value = arr.back();
    arr.pop_back();

    for (int i = 0; i < len - 1; i++) {
      if (arr[i] == value && ++count == target) return value;
    }
    len -= 1;
  }

  std::vector<int> majors;

  for (int i = 0; i < len/2; i++) {
    if (arr[2*i] == arr[2*i+1])
      majors.push_back(arr[2*i]);
  }
  return prune(majors);
}

int get_majority_element(std::vector<int> &a, int left, int right) {
  if (left == right) return -1;

  if ((left + 1) == right)
    return (a[left] == a[right]) ? a[left] : -1;

  int l,r,m;
  m = left + (right - left) / 2;

  l = get_majority_element(a, left, (m - 1));
  r = get_majority_element(a, m, right);
  
  if (l == -1 || l == r) return r;
  if (r == -1) return l;

  return -1;
}



