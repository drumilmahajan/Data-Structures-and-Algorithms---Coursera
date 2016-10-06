#include <iostream>

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int a = 0;
    int b  = 1;
    int c=0;

    for (int i = 0; i < n - 1; ++i) {
    	a=a%10;
    	b=b%10;
        c = a+b;
    	a=b;
    	b=c%10;
    }

    return c%10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
