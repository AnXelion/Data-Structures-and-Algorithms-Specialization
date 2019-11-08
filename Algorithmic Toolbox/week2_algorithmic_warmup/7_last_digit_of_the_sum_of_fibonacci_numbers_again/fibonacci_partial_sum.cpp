#include <iostream>
#include <vector>

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
    long long m = n + 2;
    std::vector<long long> pisano = get_pisano_sequence(10);
    int sum = (pisano[m % pisano.size()] > 0) ? (pisano[m % pisano.size()] - 1) : (pisano[m % pisano.size()] - 1 + 10);   

    return sum; 
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    int sum_last_digit = 0;
    
    if (from == 0) 
        sum_last_digit = fibonacci_sum_fast(to);
    else
        sum_last_digit = fibonacci_sum_fast(to) - fibonacci_sum_fast(from - 1); 
        
    return (sum_last_digit < 0) ? (sum_last_digit + 10) : sum_last_digit; //deal with the case that to_digit < from-1_digit
}


int main() {
    long long from, to;
    std::cin >> from >> to;

    // // stress test
    // while(1) {
    //     long long from = rand() % 50;
    //     long long to = rand() % 50;

    //     if (from <= to) {
    //         if ( get_fibonacci_partial_sum_naive(from, to) != get_fibonacci_partial_sum_fast(from, to)) {
    //             std::cout << "from: " << from << " to: " << to << std::endl;
    //             std::cout << "naive: " << get_fibonacci_partial_sum_naive(from, to) << std::endl;
    //             std::cout << "fast: " << get_fibonacci_partial_sum_fast(from, to) << std::endl;
    //             break;
    //         }
    //         std::cout << "[OK]" << std::endl;
    //     }
    // }

    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    
    return 0;
}
