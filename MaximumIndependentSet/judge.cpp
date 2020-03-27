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
	int N, M;
	ifs_in >> N >> M;
	vector<pair<int, int> > edges(M);
	for (int i = 0; i < M; i++) {
		ifs_in >> edges[i].first >> edges[i].second;
	}

	//input solution
	string S;
	cin >> S;

	//calc score
	assert(S.size() == N);

	for (int i = 0; i < N; i++) {
		assert(S[i] == '0' || S[i] == '1');
	}

	for (int i = 0; i < M; i++) {
		assert(S[edges[i].first] == '0' || S[edges[i].second] == '0');
	}

	int score = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') score++;
	}

	cout << score << endl;

	return 0;
}