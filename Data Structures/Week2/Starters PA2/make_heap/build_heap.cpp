#include <iostream>
#include <vector>
#include <algorithm>
//#include <cmath>
#include <climits>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int>* data_ = new vector<int>();
  vector< pair<int, int> >* swaps_ = new vector< pair<int, int> >();

  void WriteResponse() const {
    cout << swaps_->size() << "\n";
    for (int i = 0; i < swaps_->size(); ++i) {
      cout << ((*swaps_)[i]).first << " " << ((*swaps_)[i]).second << "\n";
    }

    // Freeing the memory of vectors created on heap
    data_->clear();
    swaps_->clear();
  }

  void ReadData() {
    int n;
    cin >> n;
    data_->resize(n);
    swaps_->reserve(4*n);
    for (int i = 0; i < n; i++) {
    cin>>(*data_)[i];
    }
  }

  void GenerateSwaps() {
    swaps_->clear();
    for (int i = int(data_->size()/2) - 1 ; i >= 0; i--) {
      shift_down(i);
    }
  }

  void shift_down(int i) {

    int left = 2*i + 1;
    int right = left + 1;
    int minimum = i;
    pair<int, int> p;

    if ( left <= data_->size() - 1 ) {
      if ((*data_)[minimum] > (*data_)[left])
        minimum = left;
    }
    if ( right <= data_->size() - 1 ){
        if ((*data_)[right] < (*data_)[minimum] )
            minimum = right;
    }
    if ( i != minimum ){
      p.first = i;
      p.second = minimum;
      swaps_->push_back(p);
      swap((*data_)[i], (*data_)[minimum]);
      shift_down(minimum);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  //cout<<INT_MAX ;
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
