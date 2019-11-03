#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool comparisonDigits (string a, string b) {
  std::stringstream ret;
  int int_a, int_b;

  // create ab then cast it to int
  ret << a;
  ret << b;
  ret >> int_a;

  // clear the stringstream to create ba
  ret.clear();  

  // create ba then cast it to int
  ret << b;
  ret << a;
  ret >> int_b;

  if (int_a > int_b)
    return true;
  else 
    return false;
}


string largest_number(vector<string> a) {
  //write your code here
  string result;

  sort(a.begin(), a.end(), comparisonDigits);
  
  for (int i = 0; i < a.size(); i++) {
    result += a[i];
  }
  
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  std::cout << largest_number(a);

  return 0;
}
