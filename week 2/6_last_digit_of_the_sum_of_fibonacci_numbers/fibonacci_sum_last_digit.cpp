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

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    // Get the pisano sequnce of mod 10 and the sum of it
    // The periodicity is 60 equal to the size of sequence
    std::vector<long long> pisano = get_pisano_sequence(10);
    int pisano_total_sum = 0;
    int pisano_periodicity = pisano.size();
    for (int i = 0; i < pisano_periodicity; i++) {
        pisano_total_sum += pisano[i];
    }
    
    // Sum up all last digits
    int sum = 0;
    while (n > 0) {
        if (n >= pisano_periodicity) {
            sum = ((n / pisano_periodicity) * pisano_total_sum) % 10;
            n %= pisano_periodicity;         
        }
        else {
            sum = (sum + pisano[n]) % 10;
            n--;
        }
    }

    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << std::endl;
    std::cout << fibonacci_sum_fast(n) << std::endl;
    
    return 0;
}
