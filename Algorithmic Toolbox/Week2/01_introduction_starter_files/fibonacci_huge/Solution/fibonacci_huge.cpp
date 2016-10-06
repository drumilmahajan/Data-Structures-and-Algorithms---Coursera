#include <iostream>

long long calc_fib(int n, long long m) {
    long long a=0;
    long long b=1;
    long long c =0;
    
    if(n==0)
    	return 0;
    if(n==1)
    	return 1;
    else{
	
    	for(int i = 2 ; i<=n ; i++)
    	{
    		c=a+b;
    		if(c>=m)
    			c=c%m;
    		a=b;
    		b=c;
    		
		}
		return c;
	}
}


long long get_fibonacci_huge_fast(long long n, long long m) {
	//int prev[3] = {0,0,0};
	int a=0;
	int b=1;
	int c=0;
	int period=0;
	while(n>1){
	period += 1;	
	c=a+b;
	if(c>=m)
		c=c%m;
	a=b;
	b=c;
	if(a==0 && b==1){
		//std::cout<<period<<std::endl;
		//std::cout<<prev[0]<<std::endl;
		break;
    	}
	}
	int nth = n%period;
	long long ans = calc_fib(nth,m);
	std::cout<<ans<<std::endl;
	

}


int main() {
    long long n, m;
    std::cin >> n >> m;
    get_fibonacci_huge_fast(n, m);
    //std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
