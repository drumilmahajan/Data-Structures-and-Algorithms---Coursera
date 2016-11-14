#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {

  // initializing first row and first column to zero

  //int value[W + 1][w.size()+1];
  vector<vector<int> > value;
  value.resize(W + 1, vector<int>(w.size() + 1 , 0));

  for( int i = 0; i < W + 1; i++) {
        value[i][0] = 0;
  }

  for( int j = 0; j < w.size() + 1; j++){
        value[0][j] = 0;
  }

  for( int i = 1; i < w.size() + 1; i++) {
    for( int j = 1; j < W + 1; j++){
        value[j][i] = value[j][i-1];
        //std::cout<<value[i][j]<<std::endl;
        if( w[i-1] <= j){
            int val = value[j - w[i-1]][i-1] + w[i-1];
            //std::cout<<val<<std::endl;
            if ( value[j][i] < val)
                value[j][i] = val;
        }
    }
  }
  return value[W][w.size()];
}



int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
