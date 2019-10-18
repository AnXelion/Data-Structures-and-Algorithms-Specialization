#include <iostream>
#include <vector>

using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long) numbers[i] * (long long) numbers[j] > max_product )
                max_product = (long long) numbers[i] * (long long) numbers[j];
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();
    
    int max_index_1 = -1;
    for (int i = 0; i < n; i++) {
        if ((max_index_1 == -1) || numbers[i] > numbers[max_index_1])
            max_index_1 = i;
    }

    int max_index_2 = -1;
    for (int j = 0; j < n; j++) {
        if (j != max_index_1 && (max_index_2 == -1 || numbers[j] > numbers[max_index_2]))
            max_index_2 = j;
    }

    return (long long) numbers[max_index_1] * (long long) numbers[max_index_2];
}

int main() {
    int n;
    long long result;
    
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // result = MaxPairwiseProduct(numbers);
    result = MaxPairwiseProductFast(numbers);
    cout << result << endl;

    return 0;
}