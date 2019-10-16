#include <iostream>

using namespace std;

int sum_of_two_digits(int digit1, int digit2) {
    return digit1 + digit2;
}

int main() {
    int a = 0;
    int b = 0;

    cin >> a;
    cin >> b;

    cout << sum_of_two_digits(a, b);

    return 0;
}