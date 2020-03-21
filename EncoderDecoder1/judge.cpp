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
	ifstream ifs_res1(argv[2]);
	ifstream ifs_res2(argv[3]);
	string _;

	//input problem
	int N;
	ifs_problem >> _;
	ifs_problem >> N;
	vector<string> X(N);
	for (int i = 0; i < N; i++) {
		ifs_problem >> X[i];
	}

	int len;
	//input solution
	assert(ifs_res1 >> _);
	len = _.size();

	vector<string> res(N);
	for (int i = 0; i < N; i++) {
		assert(ifs_res2 >> res[i]);
	}

	//calc score

	for (int i = 0; i < N; i++) {
		assert(X[i] == res[i]);
	}
	int score = len;
	cout << fixed << setprecision(15) << score << endl;

	return 0;
}