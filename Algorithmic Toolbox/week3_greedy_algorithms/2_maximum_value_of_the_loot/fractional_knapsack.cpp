#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <cmath>

using std::vector;

// Class for containing all three value, wieght, and values_per_weight values
// Helpful when you sort vector of loots but keep the correspoding index of value and weight
class Loot {
  private:
    int value;
    int weight;
    double values_per_weight;
  
  public:
    Loot(int v, int w, double vpw ): value(v), weight(w), values_per_weight(vpw) {}
    int getValue() { return value; }
    int getWeight() { return weight; }
    double getValuePerWeight() { return values_per_weight; }
};

bool compareValuesPerWeight(Loot a, Loot b) {
  return (a.getValuePerWeight() < b.getValuePerWeight());
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  vector<Loot> loots;
  for (int i = 0; i < weights.size(); i++) {
    loots.push_back(Loot(values[i], weights[i], (double) values[i] / weights[i]));
  }

  // sort array according to values_per_weight
  std::sort(loots.begin(), loots.end(), compareValuesPerWeight);

  for (int i = loots.size() - 1; i >= 0; i--) {
    if (capacity == 0) 
      break;

    int a = std::min(loots[i].getWeight(), capacity); // if weight[i] < capacity, take all of them. Otherwise, take the exact amount of capacity
    value = value + a * (loots[i].getValuePerWeight());
    capacity = capacity - a;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}