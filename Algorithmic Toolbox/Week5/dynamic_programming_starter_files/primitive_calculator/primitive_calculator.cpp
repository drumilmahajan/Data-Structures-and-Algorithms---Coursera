#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

std::map <int, int> recursion_values;

int optimal_sequence_dp(int n){

	// Reccursion base cases
	if(n == 0)
		return 0;
	else if ( n == 1 )
		return 0;
	else if ( n == 2 || n == 3) 
		return 1;

	else {
		
		int n_3_op = 2147483647; 
		int n_2_op = 2147483647; 
		int n_1_op = 2147483647; 
		
		if (n%3 == 0) {
			int n_3_q = n/3;
			
			if (recursion_values.find(n_3_q) == recursion_values.end()) {
				n_3_op = optimal_sequence_dp(n_3_q);
				recursion_values.insert({n_3_q, n_3_op});
			}
			else {
				n_3_op = recursion_values.find(n_3_q)->second;	
			}
		}
		
		if (n%2 == 0) {
			int n_2_q = n/2;
			
			if (recursion_values.find(n_2_q) == recursion_values.end()) {
				n_2_op = optimal_sequence_dp(n_2_q);
				recursion_values.insert({n_2_q, n_2_op});
			}
			else {
				n_2_op = recursion_values.find(n_2_q)->second;	
			}
		}

		int n_1_q = n-1;
		if (recursion_values.find(n_1_q) == recursion_values.end()) {
				n_1_op = optimal_sequence_dp(n_1_q);
				recursion_values.insert({n_1_q, n_1_op});
		}
		else {
			n_1_op = recursion_values.find(n_1_q)->second;	
		}
		
		int minimum = std::min(n_3_op,std::min(n_2_op,n_1_op));
		
		//std::cout<<"else called"<<std::endl;
		return 1 + minimum; 
		
	}	 	
	
}


int main() {
  int n;
  std::cin >> n;
  //vector<int> sequence = optimal_sequence(n);
  int sequence = optimal_sequence_dp(n);	
  //std::cout << sequence.size() - 1 << std::endl;
  /*
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  */
  std::cout << sequence << " ";
}
