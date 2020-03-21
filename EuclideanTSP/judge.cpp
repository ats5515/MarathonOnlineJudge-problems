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
	ifstream ifs_in(argv[1]);

	//input problem
	int N;
	ifs_in >> N;
	vector<int> X(N);
	vector<int> Y(N);
	for (int i = 0; i < N; i++) {
		ifs_in >> X[i] >> Y[i];
	}

	//input solution
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		cin >> res[i];
	}

	//calc score
	const double INVALID = 1e6;
	double score = 0;
	bool valid = true;
	set<int> st;
	for (int i = 0; i < N; i++) {
		if (res[i] < 0 || res[i] >= N) {
			valid = false;
		}
		st.insert(res[i]);
	}
	if (st.size() != N) valid = false;
	if (!valid) {
		score = INVALID;
	} else {
		score = 0;
		for (int i = 0; i < N; i++) {
			int a = res[i];
			int b = res[(i + 1) % N];
			score += hypot(X[a] - X[b], Y[a] - Y[b]);
		}
	}
	cout << fixed << setprecision(15) << score << endl;
	return 0;
}