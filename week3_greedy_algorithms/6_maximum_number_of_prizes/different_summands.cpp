#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  summands.push_back(1);
  int remain = n-1;
  int index = 0;

  while (remain > 0) {
    if (remain > summands[index]) { // if remain > summands[index], push back summands[index]+1 to the vector
      summands.push_back(summands[index] + 1);
      remain -= summands[++index];  // update remain
    }

    else {
      summands[index] += remain;  // plus the rest of remain to the last element
      remain = 0;
    }  
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
