#include <assert.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifs_problem(argv[1]);
	
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != '0' && S[i] != '1') {
			assert(false);
		}
	}
	string _;
	if (cin >> _) assert(false);

	cout << "decoder" << endl;
	cout << S << endl;

	return 0;
}