#include <iostream>

int get_fibonacci_last_digit_fast(long long n) {
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
	//std::cout<<last<<std::endl;
    int ans = last+9;
	//std::cout<<ans;  
  	return ans%10;
}

	

int main() {
  long long n = 0;
  std::cin >> n;
  std::cout << fibonacci_sum(n);
}
