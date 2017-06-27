#include <iostream>
#include <vector>


int binary_search(const std::vector<int> &arr, int numToFind) {
  int left = 0;
  int right = (int)arr.size();
  int mid;

  while(left != right) {
    mid = (left + right) / 2;

    if(arr[mid] == numToFind) {
      break;
    }


    if(arr[mid] < numToFind) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return (arr[mid] == numToFind) ? mid : -1;
}

int linear_search(const std::vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x)
        return (int)i;
  }
  return -1;
}

//int main() {
//  // put the test array here, make sure the numbers are in order:
//  std::vector<int> a = {1, 5, 8, 12, 13};
//
//  // put the terms to search for here:
//  std::vector<int> b = {8, 1, 23, 1, 11};
//
//  std::cout << "___Array___" << std::endl;
//  std::cout << "[";
//  for(int j = 0; j < a.size(); j++) {
//    std::cout << a[j] << ' ';
//  }
//  std::cout << "]" << std::endl;
//
//  for (int i = 0; i < b.size(); ++i) {
//
//    std::cout << "Searching for " << b[i] << std::endl;
//
//    std::cout << "Linear Search Result: " << linear_search(a, b[i]) << ' ' << std::endl;
//    std::cout << "Binary Search Result: " << linear_search(a, b[i]) << ' ' << std::endl << std::endl;
//  }
//
//  std::cout << "__END__" << std::endl;
//  return 0;
//}

// here is the main for the answer
int main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  int m;
  std::cin >> m;
  std::vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
