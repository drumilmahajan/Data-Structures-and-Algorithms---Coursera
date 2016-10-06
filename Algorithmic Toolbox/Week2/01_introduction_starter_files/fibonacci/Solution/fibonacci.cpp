#include <iostream>

long calc_fib(int n) {
    long a=0;
    long b=1;
    long c =0;
    
    if(n==0)
    	return 0;
    if(n==1)
    	return 1;
    else{
	
    	for(int i = 2 ; i<=n ; i++)
    	{
    		c=a+b;
    		a=b;
    		b=c;
    		
		}
		return c;
	}
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
