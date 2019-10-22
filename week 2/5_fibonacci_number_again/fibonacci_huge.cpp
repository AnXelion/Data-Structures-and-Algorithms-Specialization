#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_with_pisano_sequence(long long n, long long m) {
    if (n <= 1) 
        return n;
   
    // Get pisano sequence
    std::vector<long long> pisano{0, 1};
    long long previous = 0;
    long long current = 1;

    while (1) { // pisano squence could be longer than n so that we use infinite loop instead of for loop from 2 -> n 
        long long tmp_previous = previous;
        previous = current;
        current = (current + tmp_previous) % m; 

        if ((current == 1) && (previous == 0)) {
            pisano.pop_back(); // eliminate the first duplicate periodic element
            break;
        }

        pisano.push_back(current);
    }

    // Print pisano sequence
    // for (int i = 0; i < pisano.size(); i++)
    //     std::cout << pisano[i] << " ";

    // // Calculate Fn mod m
    // std::cout << "pisano size: " << pisano.size() << std::endl;
    int pisano_index = n % (pisano.size());
    // std::cout << "pisano index: " << pisano_index << std::endl;
    return pisano[pisano_index];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_with_pisano_sequence(n, m) << '\n';

    return 0;
}
