#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool segementsComparison(Segment &a, Segment &b) {
    return (a.end < b.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  // write your code here
  // Sort segments according to end points
  sort(segments.begin(), segments.end(), segementsComparison);

  int point = segments[0].end;  // the first rightmost point
  points.push_back(point);

  for (int i = 1; i < segments.size(); i++) {
    if ((point < segments[i].start)) { // the point is not in the segment
      point = segments[i].end;  // update the point to the rightmost of this segment
      points.push_back(point);  
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
}
