#include <iostream>
#include <vector>

using namespace std;

int MaxPairwiseProduct(const vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] * numbers[j] > max_product )
                max_product = numbers[i] * numbers[j];
        }
    }

    return max_product;
}


int main() {
    int n, result;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    result = MaxPairwiseProduct(numbers);
    cout << result << endl;

    return 0;
}