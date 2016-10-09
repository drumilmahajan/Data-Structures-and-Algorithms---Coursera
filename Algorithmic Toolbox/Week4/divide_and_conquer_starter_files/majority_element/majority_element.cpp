#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (right == -1) return -1;
  if (left == right) return a[left];

  else {

    int major_l = get_majority_element(a , left , ((right - left ) / 2) + left);
    int major_r = get_majority_element(a, ((right-left)/2) + 1 + left , right);
    
    if ( major_r == -1 && major_l  == -1 ) return -1;
    
    if (major_l == major_r)
    {
    	return major_l;
	}
	
	if (major_l >=0) {
		for(int i = ((right-left)/2) + 1 + left; i <= right ; i++){
			if(major_l == a[i]) {
				return major_l;
			}
		}	
	}
	
	if ( major_r >= 0){
		for(int i = left ; i <= (right-left)/2 + left ; i++) {
			if(major_r == a[i]) {
				return major_r;
			}
		}
	}
	else return -1;
	
  }
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int count = 0;
  int number = get_majority_element(a, 0, a.size()-1);
  
  if (number == -1) std::cout<<0;
  else {
	 for(int i = 0; i < a.size() ; i++){
	 	if (number == a[i]) 
	 		count++;
	 }
	 if (count > n/2 )
  		std::cout<<1;
  	 else std::cout<<0;
  }
  
}
