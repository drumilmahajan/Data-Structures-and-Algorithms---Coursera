#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Node {
	int key_value; // value of the node
	Node *left; // left node will contain result of num -1 operation
	Node *middle; // middle node will contain result of /2 operation if divisible
	Node *right; // right node will contain result of /3 operation if divisible
};


vector<int> optimum_sequence_dp(int n){
	std::vector<int> sequence;
	Node root = new Node;
	node->
	
	while(n >= 1) {
		
	}
	
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
