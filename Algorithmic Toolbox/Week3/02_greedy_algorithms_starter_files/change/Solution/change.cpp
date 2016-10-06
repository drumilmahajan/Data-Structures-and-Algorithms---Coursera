#include <iostream>

int get_change(int m) {
  int change = 0;
  if(m>=10){
  change = m/10;
  m = m%10;
  }
  if(m>=5){
  	change = change + m/5;
  	m = m%5; 	
  }
  if(m>=1)
  {
  	change = change + m;
  }
  return change;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
