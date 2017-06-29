#include <algorithm>
#include <iostream>
#include <vector>

int get_majority_element(std::vector<int> &a, int left, int right);
int linear_majority(std::vector<int> &a);
int prune(std::vector<int> arr);

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

//  int maj = get_majority_element(a, 0, (a.size() - 1));
  int maj = linear_majority(a);
  std::cout << maj << '\n';
  std::cout << (maj != -1) << '\n';
}

int linear_majority(std::vector<int> &a) {
  int x = prune(a);
  int len = a.size();

  std::cout << "The maj is: " << x << std::endl;
  int count = 0;
  std::cout << "The length is :" << a.size() << std::endl;
  for (int i = 0; i < len; i++) {
    std::cout << "i: " << i << std::endl;
    if (a[i] == x && ++count == len/2+1 ) {
      std::cout << "The count made it " << count<< std::endl;
      return x;
    }
    std::cout << "The count: " << count << "/" << len/2+1 << std::endl;
  }
  std::cout << "The count was short: " << count << "/" << len/2+1 << std::endl;
  return -1;
}

int prune(std::vector<int> arr) {
  int len = arr.size();

  if (len == 0) return -1;
  if (len == 1) return arr[0];
  if (len % 2 == 1) {
    int value = arr.back();
    arr.pop_back();
    return value;
  }

//  if (len % 2 == 1) {
//    int count = 1;
//    int target = len / 2 + 1;
//    int value = arr.back();
//    arr.pop_back();
//
//    for (int i = 0; i < len - 1; i++) {
//      if (arr[i] == value && ++count == target) return value;
//    }
//    len -= 1;
//  }

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



