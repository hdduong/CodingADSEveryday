#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int count_permutation(int k, const vector<int> &score_ways) {
	vector<int> permutations(k+1,0);

	permutations[0] = 1;

	for (int i = 0; i <=k;i++) {
		for (const int & score : score_ways) {
			if (i >= score) {
				permutations[i] += permutations[i - score];
			}
		}
	}
	return permutations[k];
}


int count_combinations(int k, const vector<int>& score_ways) {
  vector<int> combinations(k + 1, 0);
  combinations[0] = 1;  // one way to reach 0.
  
  for (const int& score : score_ways) {
    for (int j = score; j <= k; ++j) {
      combinations[j] += combinations[j - score];
    }
  }
  return combinations[k];
}


void simple_test() {
  int k = 6;
  vector<int> score_ways;
  score_ways.push_back(2);
  score_ways.push_back(3);
  score_ways.push_back(7);
  cout << count_combinations(k, score_ways) << endl;
  cout << count_permutation(k, score_ways) << endl;
}




int main() {
	simple_test();
	return 0;
}