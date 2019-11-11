#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = (left + right) / 2;
  int left_element = get_majority_element(a, left, mid - 1);
  int right_element = get_majority_element(a, mid, right);

  int l_count = 0;
  for (int i = left; i < right; i++) {
    if (a[i] == left_element)
      l_count++;
  }
  if (l_count > (right - left) / 2) return left_element;

  int r_count = 0;
  for (int i = left; i < right; i++) {
    if (a[i] == right_element)
      r_count++;
   }
  if (r_count > (right - left) / 2) return right_element;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
