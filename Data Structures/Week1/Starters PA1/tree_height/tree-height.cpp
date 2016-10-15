#include <iostream>
#include <vector>
#include <algorithm>

class TreeHeight {
  int n; // number of nodes in the tree            
  std::vector<int> parent; // Parent vector which will store the tree
  int h; // variable which will store the height
  std::vector<int> height; // height vector which will store the height from every node.

public:
		
  void read() {
  	h = 0; // initilizing height to zero
    std::cin >> n; // The input format is given in the question. if the array value is -1, it is the root else the value is the parent. 
    parent.resize(n);
    height.resize(n);
	for (int i = 0; i < n; i++){
		std::cin >> parent[i];  // Saving the input to the parent vector
      	height[i] = -1; // Initilizing height vector by -1, That is height at all the nodes is unknown.
  	}
  }
  	// The function to compute height
	int compute_height() {
	// This loop calls the compute height of node function if the height to that node is unknown.
	for( int i = 0 ; i < n ; i++) {
		if (height[i] == -1){
			height[i] = compute_height_of_node(parent[i]);
			//std::cout<<"height : "<<height[i]<<std::endl;
			h = std::max(h, height[i]); // stores the maximum height. 
			}	
		}
	return h; // returns the maximum height
	}

	int compute_height_of_node(int node) { 
	//std::cout<<"I am the recursive function and I am called "<<std::endl ;
    // If on root node. Return 1. Root node has value -1 in parent array.
	if ( node == -1) { 
    	return 1;
	}
	else {
		// if height of the parent of node is unknown than make a recursive call else use height from height array. 
		if (height[node] == -1) {
			height[node] = compute_height_of_node(parent[node]); 	
			return 1 + height[node];
		}
		// Using height from height array
		else
			return 1 + height[node]; // For every call. Returning 1 + height of parent node. 
		}
  	}
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read(); // Reading the input
  std::cout << tree.compute_height() << std::endl; // Printing the maximum tree height. 
}
