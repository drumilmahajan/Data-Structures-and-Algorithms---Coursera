#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();

    for (int i = int(std::floor(data_.size())); i > 0; i--) {
        int minimum = 0;
        if (data_[i] < data_[2*i]) {
            minimum = i;
        }
        else {
            minimum = 2*i;
        }
        if (data_[2*i + 1] <= data_.size()) {
            if ( data_[2*i + 1] < data_[minimum] ){
                minimum = 2*i + 1;
            }
        }
        if (minimum == 2*i || minimum == 2*i + 1){
                pair<int, int> p;
                p.first = i;
                p.second = minimum;
                swaps_.push_back(p);
                swap(data_[i], data_[minimum]);
        }
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
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
