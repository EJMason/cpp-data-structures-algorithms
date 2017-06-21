#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
    Segment(){};
    Segment(int a, int b) : start(a), end(b) {}
};

int partition(vector<Segment>& arr, int startIdx, int endIdx) {
  double pivot = arr[startIdx].end;
  int i = startIdx;

  int j;
  for(j = startIdx + 1; j < endIdx; j++) {
    if(arr[j].end <= pivot) {
      i = i + 1;
      std::swap(arr[i],arr[j]);
    }
  }

  std::swap(arr[i],arr[startIdx]);
  return i;
}

// 0 to number of items
void quicksort(vector<Segment>& arr, int leftEdge, int rightEdge) {
  int pivot;

  if (leftEdge < rightEdge) {
    pivot = partition(arr, leftEdge, rightEdge);

    quicksort(arr, leftEdge, pivot);
    quicksort(arr, pivot + 1, rightEdge);
  }
}


// ------------------------ Start ------------------------  //
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int current;

  quicksort(segments, 0, segments.size());

  vector<Segment>::iterator it = segments.begin();
  points.push_back(it->end);
  current = points[0];
  ++it;

  for(it; it != segments.end(); ++it) {
    if (it->start > current) {
      points.push_back(it->end);
      current = it->end;
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);

  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);

  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }

  return 0;
}
