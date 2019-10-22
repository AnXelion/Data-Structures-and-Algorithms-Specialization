#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

std::vector<long long> get_pisano_sequence(long long m) {
    std::vector<long long> pisano{0, 1};
    long long previous = 0;
    long long current = 1;

    while (1) {
        long long tmp_previous = previous;
        previous = current;
        current = (current + tmp_previous) % m; 
       
        if ((current == 1) && (previous == 0)) {
            pisano.pop_back(); // eliminate the first duplicate periodic element
            break;
        }

        pisano.push_back(current);
    }

    return pisano;
}

// Using the fact that ∑Fn = Fn+2 - 1.
int fibonacci_sum_fast(long long n) {
    if (n <= 1) 
        return n;

    long long m = n + 2;
    std::vector<long long> pisano = get_pisano_sequence(10);
    int sum = (pisano[m % pisano.size()] > 0) ? (pisano[m % pisano.size()] - 1) : 9;   

    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << std::endl;
    std::cout << fibonacci_sum_fast(n) << std::endl;
    
    return 0;
}
