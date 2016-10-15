#include <iostream>
#include <vector>
#include <algorithm>

class TreeHeight {
  int n;             
  std::vector<int> parent;
  int h;
  std::vector<int> height;

public:
		
  void read() {
    std::cin >> n;
    parent.resize(n);
    height.resize(n);
	for (int i = 0; i < n; i++){
	
      std::cin >> parent[i];
      height[i] = -1;
  	}
  }
  	
	int compute_height() {
	
	for( int i = 0 ; i < n ; i++) {
		if (height[i] == -1){
			height[i] = compute_height_of_node(parent[i]);
			std::cout<<"height : "<<height[i]<<std::endl;
			h = std::max(h, height[i]);
			}	
		}
	return h;
	}

	int compute_height_of_node(int node) { 
	//std::cout<<"I am the recursive function and I am called "<<std::endl ;
    if ( node == -1) {
    	return 1;
	}
	else {
		if (height[node] == -1) {
			height[node] = compute_height_of_node(parent[node]); 	
			return 1 + height[node];
		}
		else
			return 1 + height[node];
		}
  	}
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
