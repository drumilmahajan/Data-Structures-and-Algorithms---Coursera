#include <iostream>

int gcd_euclid(int a, int b) {
  	if(b>=a && b%a==0)
  		return a;
	if(a>=b && a%b==0)
  		return b;
	else if(a>b)
		return gcd_euclid(b,a%b);
	else if(b>a)
		return gcd_euclid(a,b%a);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclid(a, b) << std::endl;
  return 0;
}
