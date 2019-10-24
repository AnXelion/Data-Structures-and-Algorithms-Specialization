#include <cstdlib>
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
    // int n;
    // long long result;
    
    // cin >> n;

    // vector<int> numbers(n);

    // for (int i = 0; i < n; i++) {
    //     cin >> numbers[i];
    // }

    // // result = MaxPairwiseProduct(numbers);
    // result = MaxPairwiseProductFast(numbers);
    // cout << result << endl;

    int n = rand() % 10 + 2;
    vector<int> numbers(n, 0);

    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 100000;
    }

    long long result1, result2;

    while (1) {
        result1 = MaxPairwiseProduct(numbers);
        result2 = MaxPairwiseProductFast(numbers);

        if (result1 != result2) {
            cout << "[Fail] result1: " <<  result1 << " result2: " << result2 << endl; 
            break;
        }
        cout << "[OK]" << endl;
    }
    
    


    return 0;
}