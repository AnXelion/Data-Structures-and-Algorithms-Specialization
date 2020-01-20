#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


// int partition2(vector<int> &a, int l, int r) {
//   int x = a[l];
//   int j = l;
//   for (int i = l + 1; i <= r; i++) {
//     if (a[i] <= x) {
//       j++;
//       swap(a[i], a[j]);
//     }
//   }
//   swap(a[l], a[j]);
//   return j;
// }

vector<int> partition3(vector<int> &a, int l, int r) {
  int pivot = a[l];
  int j = l, t = r;

  for (int i = l + 1; i <= t; i++) {
    if (a[i] < pivot) {
      swap(a[i], a[j]);
      j++;
    }

    else if (a[i] > pivot) {
      swap(a[i], a[t]);
      t--;
      i--;
    }
  }  
  // swap(a[l], a[j]);  // Don't need this in 3-way partition compared to 2-way partition.
  return vector<int> {j,t};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> p = partition3(a, l, r);

  randomized_quick_sort(a, l, p[0] - 1);
  randomized_quick_sort(a, p[1] + 1, r);
}

// // version with partition2 
// void randomized_quick_sort(vector<int> &a, int l, int r) {
//   if (l >= r) {
//     return;
//   }

//   int k = l + rand() % (r - l + 1);
//   swap(a[l], a[k]);
//   int m = partition2(a, l, r);

//   randomized_quick_sort(a, l, m - 1);
//   randomized_quick_sort(a, m + 1, r);
// }

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
