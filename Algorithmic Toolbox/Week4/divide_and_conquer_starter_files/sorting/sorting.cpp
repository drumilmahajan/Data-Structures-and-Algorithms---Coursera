#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


// Three way partitioning created to take into account equal elements. 
std::vector<int> partition3(vector<int> &a, int l, int r) {
  std::vector<int> m3(2); // Vecotr to store left and right indicies of equal elements. 
  int x = a[l]; // storing the pivot as the first element
  int j = l; // j is the marker for the elemnts less than or equal to the pivot.
  int equal = 0; // stores the number of elements equal to pivot found (excluding the pivot) 
  for (int i = l + 1; i <= r; i++) {  // Traversing the array from the element next to pivot to the last. 
    if (a[i] == x) { // In case of equal element. 
      j++; // Moving the j pointer
      equal ++; // Incrementing the number of equal elemnts by 1. 
      swap(a[i], a[j]); // swapping i and j. 
    }
    // If a[x] < x 
    else if (a[i] < x) {
      j++; // MOving the marker 
      swap(a[i], a[j]); // Swapping to move the smaller element to the left side 
      swap(a[l], a [j]); // Swapping to keep the equal elements together
      l++; // Incrementing l to keep all equal elements together. 
	}
  //std::cout<<"l :"<<l<<"\n";
  //std::cout<<"l+equal :"<<l+equal<<"\n";
  }
  // returning the two pivots where all elements between l and l+equal are equal
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
  randomized_quick_sort(a, l, m[0] - 1);  // recursive call to left half
  randomized_quick_sort(a, m[1] + 1, r); // recursive call to right half
}

int main() {
  int n; // number of elements
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
