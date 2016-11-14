#include <iostream>
#include <string>
#include <vector>

using std::string;

int edit_distance(const string &str1, const string &str2) {

  std::vector< std::vector<int> > D;
  // resizing for rows and columns
  // D.resize(rows , vector<Type>(columns, initial value))
  D.resize(str1.length() + 1, std::vector<int>(str2.length() + 1 , 0));

  //Filling the first row and column of the array
  for (int i = 1; i<=str1.length(); i++) {
    D[i][0] = i;
  }
  for (int i = 1; i<=str2.length(); i++) {
    D[0][i] = i;
  }

  // Filling the remaining array
  for ( int j = 1 ; j <= str2.length() ; j++) {
    for ( int i = 1 ; i <= str1.length() ; i++) {
      int insertion = D[i][j-1] + 1;
      int deletion = D[i-1][j] + 1;
      int match = D[i-1][j-1];
      int mis_match = D[i-1][j-1] + 1;
      if ( str1[i-1] == str2[j-1])
        D[i][j] = std::min(insertion , std::min(deletion, match));
      else
        D[i][j] = std::min(insertion , std::min(deletion, mis_match));

    }
  }


  return D[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
