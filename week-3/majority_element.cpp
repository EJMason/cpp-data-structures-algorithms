#include <algorithm>
#include <iostream>
#include <vector>

//int get_majority_element(std::vector<int> &a, int left, int right);
int linear_majority(std::vector<int> &a);
int prune(std::vector<int> arr);
int sort_solution(std::vector<int> &arr);

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
//  int maj = get_majority_element(a, 0, (a.size() - 1));
//  std::cout << linear_majority(a) << '\n';
  std::cout << (linear_majority(a) != -1) << '\n';

}

int linear_majority(std::vector<int> &a) {
  int x = prune(a);
  int len = a.size();

  int count = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] == x && ++count == len/2+1 ) {
      return x;
    }
  }

  return -1;
}

int prune(std::vector<int> arr) {
  int len = arr.size();
  int extra = -1;

  if (len == 0) return -1;
  if (len == 1) return arr[0];

  if (len % 2 == 1) {
    extra = arr.back();
    arr.pop_back();
  }
  std::vector<int> majors;

  for (int i = 0; i < len/2; i++) {
    if (arr[2*i] == arr[2*i+1]) {
      majors.push_back(arr[2*i]);

      if (majors.back() == extra) {
        majors.push_back(extra);
        extra = -1;
      }
    }
  }
  if(majors.size() == 0 && extra != -1) majors.push_back(extra);

  return prune(majors);
}

int sort_solution(std::vector<int> &arr) {
  int len = arr.size();
  if(len == 0) return -1;
  if (len == 1) return arr[0];

  std::sort(arr.begin(), arr.end());

  int target = arr.size()/2 + 1;
  int current = arr[0];
  int total = 0;

  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] == current) {
      total++;
//      std::cout << current << " has repeated " << total << " times. TARGET: " << target <<"|" << arr.size() << "\n";
      if (total >= target) return arr[i];
    } else {
      total = 1;
      current = arr[i];
    }
  }

  return -1;
}

//int get_majority_element(std::vector<int> &a, int left, int right) {
//  if (left == right) return -1;
//
//  if ((left + 1) == right)
//    return (a[left] == a[right]) ? a[left] : -1;
//
//  int l,r,m;
//  m = left + (right - left) / 2;
//
//  l = get_majority_element(a, left, (m - 1));
//  r = get_majority_element(a, m, right);
//
//  if (l == -1 || l == r) return r;
//  if (r == -1) return l;
//
//  return -1;
//}



