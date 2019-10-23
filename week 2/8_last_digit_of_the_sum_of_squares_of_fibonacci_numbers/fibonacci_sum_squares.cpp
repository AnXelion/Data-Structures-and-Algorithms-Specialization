#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

// Using the fact that Sigma Fn^2 equals Fn * Fnplus1
int fibonacci_sum_squares_fast(long long n) {
    long long Fn, Fn_plus_1;
    
    std::vector<long long> pisano = get_pisano_sequence(10);

    Fn_plus_1 = pisano[(n + 1) % pisano.size()];
    Fn = pisano[(n) % pisano.size()];

    return (Fn_plus_1 * Fn) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n) << std::endl;
    std::cout << fibonacci_sum_squares_fast(n) << std::endl;

    // Stress test
    // while (1) {
    //     n = rand() % 35;
    //     if (fibonacci_sum_squares_naive(n) != fibonacci_sum_squares_fast(n)) {
    //         std::cout << "n: " << n << std::endl;
    //         std::cout << "Naive: " << fibonacci_sum_squares_naive(n) << " Fast: " << fibonacci_sum_squares_fast(n) << std::endl;
    //         break;
    //     }

    //     std::cout << "[OK]" << std::endl;
    // }

    return 0;
}
