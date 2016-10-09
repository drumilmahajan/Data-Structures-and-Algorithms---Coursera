#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

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

std::vector<int> partition3(vector<int> &a, int l, int r) {
  std::vector<int> m3;
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
  }
  return {l,l+equal};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  std::vector<int> m;
  if (l >= r) {
    return;
  }
  
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  m = partition3(a, l, r);
  std::cout<<a[m[0]]<<" "<<a[m[1]];
  //randomized_quick_sort(a, l, m[0] - 1);
  //randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  //for (size_t i = 0; i < a.size(); ++i) {
  //  std::cout << a[i] << ' ';
  //}
}
