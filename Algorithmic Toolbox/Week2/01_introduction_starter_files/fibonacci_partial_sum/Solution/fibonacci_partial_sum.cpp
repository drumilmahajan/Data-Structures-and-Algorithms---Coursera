#include <iostream>
#include <vector>
using std::vector;

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

int fibonacci_sum(long long n) {
  
	int last = get_fibonacci_last_digit_fast(n+2);
	int sLast = get_fibonacci_last_digit_fast(n-1);
    int ans = last*((sLast+last)%10);  
  	return ans%10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    
	int last = get_fibonacci_last_digit_fast(to+2) + 9;
	int sLast = get_fibonacci_last_digit_fast(from + 2) + 9;
    
    return (last - sLast + 10)%10;	
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
