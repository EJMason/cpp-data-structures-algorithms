#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

/* This function partitions a[] in three parts
        a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
        c) a[j..r] contains all elements greater than pivot */
void partition(int myArray[], int paramLeft, int paramRight, int &outside_i, int &outside_j)
{
  outside_i = paramLeft - 1;
  outside_j = paramRight;
  int p = paramLeft-1;
  int q = paramRight;
  int lastElementValue = myArray[paramRight];

  while (true) {
    // From left, find the first element greater than
    // or equal to lastElementValue. This loop will definitely terminate
    // as lastElementValue is last element
    while (myArray[++outside_i] < lastElementValue);

    // From right, find the first element smaller than or
    // equal to lastElementValue
    while (myArray[--outside_j] > lastElementValue) {
      if (outside_j == paramLeft) {
        break;
      }
    }
    /*
      #######################################################
      ##############   This is the exit case   ##############
      #######################################################
   */
    // If outside_i and outside_j cross, then we are done
    if (outside_i >= outside_j) {
      break;
    }

    // Swap, so that smaller goes on left greater goes on right
    swap(myArray[outside_i], myArray[outside_j]);

    // Move all same left occurrence of pivot to beginning of
    // array and keep count using p
    if (myArray[outside_i] == lastElementValue) {
      p++;
      swap(myArray[p], myArray[outside_i]);
    }

    // Move all same right occurrence of pivot to end of array
    // and keep count using q
    if (myArray[outside_j] == lastElementValue)
    {
      q--;
      swap(myArray[outside_j], myArray[q]);
    }
  }
  // ========== END LOOP ============== //

  // Move pivot element to its correct index
  swap(myArray[outside_i], myArray[paramRight]);

  // Move all left same occurrences from beginning
  // to adjacent to arr[outside_i]
  outside_j = outside_i-1;
  for (int k = paramLeft; k < p; k++, outside_j--){
    swap(myArray[k], myArray[outside_j]);
  }


  // Move all right same occurrences from end
  // to adjacent to arr[outside_i]
  outside_i = outside_i+1;
  for (int k = paramRight-1; k > q; k--, outside_i++) {
    swap(myArray[outside_i], myArray[k]);
  }

}






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

// A utility function to print an array
void printarr(int a[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d  ", a[i]);
  printf("\n");
}

// Driver program
int main()
{
  int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
  int size = sizeof(a) / sizeof(int);
  printarr(a, size);
  quicksort(a, 0, size - 1);
  printarr(a, size);
  return 0;
}