#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
// This function is provided by coursera which uses two partitioning in quick sort. Bad for equal elements. 
int partition2(vector<int> &a, int l, int r) {
   
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

// Three way partitioning created to take into account equal elements. 
std::vector<int> partition3(vector<int> &a, int l, int r) {
  std::vector<int> m3(2); // Vecotr to store left and right indicies of equal elements. 
  int x = a[l];
  int j = l;
  int equal = 0;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] == x) {
      j++;
      equal ++;
      swap(a[i], a[j]);
    }
    else if (a[i] < x) {
      j++; 
      swap(a[i], a[j]);
      swap(a[l], a [j]);
      l++;
	}
  //std::cout<<"l :"<<l<<"\n";
  //std::cout<<"l+equal :"<<l+equal<<"\n";
  }
  m3[0] = l;
  m3[1] = l+equal;
  //std::cout<<"\n";
  return m3; // Returning the vector
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  std::vector<int> m;
  if (l >= r) {
    return;
  }
  
  int k = l + rand() % (r - l + 1);
  
  swap(a[l], a[k]);
  m = partition3(a, l, r); // Receives the two indicies from partition three procedure and make recursive calls. 
  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // Apply randomized quick sort 3 to the input array. 
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' '; // Outputs the array. 
  }
}
