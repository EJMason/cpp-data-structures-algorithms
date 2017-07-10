#include <iostream>
#include <vector>
#include <cstdlib>

//using std::vector;
//using std::swap;

using namespace std;

//int partition2(vector<int> &a, int l, int r) {
//  int x = a[l];
//  int j = l;
//  for (int i = l + 1; i <= r; i++) {
//    if (a[i] <= x) {
//      j++;
//      swap(a[i], a[j]);
//    }
//  }
//  swap(a[l], a[j]);
//  return j;
//}
//
//void randomized_quick_sort(vector<int> &a, int l, int r) {
//  if (l >= r) {
//    return;
//  }
//
//  int k = l + rand() % (r - l + 1);
//  swap(a[l], a[k]);
//  int m = partition2(a, l, r);
//
//  randomized_quick_sort(a, l, m - 1);
//  randomized_quick_sort(a, m + 1, r);
//}

// ================================================ //

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition(int a[], int l, int r, int &i, int &j)
{
  i = l-1, j = r;
  int p = l-1, q = r;
  int v = a[r];

  while (true) {
    while (a[++i] < v);

    while (v < a[--j])
      if (j == l)
        break;

    if (i >= j) break;

    swap(a[i], a[j]);

    if (a[i] == v) {
      p++;
      swap(a[p], a[i]);
    }

    if (a[j] == v) {
      q--;
      swap(a[j], a[q]);
    }
  }

  swap(a[i], a[r]);

  j = i-1;
  for (int k = l; k < p; k++, j--)
    swap(a[k], a[j]);

  i = i+1;
  for (int k = r-1; k > q; k--, i++)
    swap(a[i], a[k]);
} // ================= END FN ============== //

// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
  if (r <= l) return;

  int i, j;

  // Note that i and j are passed as reference
  partition(a, l, r, i, j);

  // Recur
  quicksort(a, l, j);
  quicksort(a, i, r);
}

void printarr(int a[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d  ", a[i]);
  printf("\n");
}

int main() {
  int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
  int size = sizeof(a) / sizeof(int);
  printarr(a, size);
  quicksort(a, 0, size - 1);
  printarr(a, size);
  return 0;
}


//int main() {
//  int n;
//  std::cin >> n;
//  vector<int> a(n);
//  for (size_t i = 0; i < a.size(); ++i) {
//    std::cin >> a[i];
//  }
//  randomized_quick_sort(a, 0, a.size() - 1);
//  for (size_t i = 0; i < a.size(); ++i) {
//    std::cout << a[i] << ' ';
//  }
//}
