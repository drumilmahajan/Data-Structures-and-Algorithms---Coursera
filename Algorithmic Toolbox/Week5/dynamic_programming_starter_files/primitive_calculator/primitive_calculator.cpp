#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using std::vector;

std::map <int, vector<int> > recursion_values;

vector<int> optimal_sequence_dp(int n){
	
	// Reccursion base cases
	if ( n == 1 ) {
		vector<int> sequence; 
		sequence.push_back(1);
		return sequence ;
	}
	else if ( n == 2 || n == 3) {
		vector<int> sequence; 
		sequence.push_back(1);
		sequence.insert(sequence.begin(), n);
		return sequence;
	}
	else {
		
		// Initialized with maximum possible value of integer
		vector<int> n_3_op; 
		vector<int> n_2_op; 
		vector<int> n_1_op;  
		
		// Case when number is divided by 3
		if (n%3 == 0) {
			
			// quotient
			int n_3_q = n/3;
			
			// If recursion of quotient is never made then make the call and add the recursion value to the map
			if (recursion_values.find(n_3_q) == recursion_values.end()) {
				
				vector<int> n_3_op = optimal_sequence_dp(n_3_q);
				recursion_values.insert({n_3_q, n_3_op});
			}
			// If recursion has already been made then use the value of recursion from the map
			else {
				n_3_op = recursion_values.find(n_3_q)->second;	
			}
		}
		
		// Case when number is divisible by 2
		if (n%2 == 0) {
			// Quotient
			int n_2_q = n/2;
			
			// If recursion of quotient is never made then make the call and add the recursion value to the map
			if (recursion_values.find(n_2_q) == recursion_values.end()) {
				n_2_op = optimal_sequence_dp(n_2_q);
				recursion_values.insert({n_2_q, n_2_op});
			}
			
			// If recursion has already been made then use the value of recursion from the map
			else {
				n_2_op = recursion_values.find(n_2_q)->second;	
			}
		}

		// Case for num - 1; 
		int n_1_q = n-1;
		
		// If recursion of n - 1 is not made then make the call and save the return value to the map
		if (recursion_values.find(n_1_q) == recursion_values.end()) {
				n_1_op = optimal_sequence_dp(n_1_q);
				recursion_values.insert({n_1_q, n_1_op});
		}
		
		// If recursion call of n-1 already made then use the value from the map
		else {
			n_1_op = recursion_values.find(n_1_q)->second;	
		}
		
		int size_3 = n_3_op.size();
		if (size_3 == 0)
			size_3 = INT_MAX; 
		int size_2 = n_2_op.size();
		if (size_2 == 0)
			size_2 = INT_MAX;
		int size_1 = n_1_op.size();
		if (size_1 == 0)
			size_1 = INT_MAX;

		int minimum = std::min(size_3,std::min(size_2,size_1));
		
		if(minimum == size_3){
			n_3_op.insert(n_3_op.begin(), n);
			return n_3_op;
		} else if(minimum == size_2) {
			n_2_op.insert(n_2_op.begin(), n);
			return n_2_op;
		} else {
			n_1_op.insert(n_1_op.begin(), n);
			return n_1_op;
		}

	}	 	
	
}


int main() {
  int n;
  std::cin >> n;
  //sequence.push_back(n);
  vector<int> sequence = optimal_sequence_dp(n);	
  std::cout << sequence.size() - 1 << std::endl;
  
  for (int i = (sequence.size() - 1); i >=0 ; i--) {
  	//int i = (sequence.size() - 1);
    std::cout << sequence[i] << " ";
  }
  
  return 0;
}
