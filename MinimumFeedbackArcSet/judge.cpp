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
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		cin >> res[i];
	}

	//calc score
	set<int> st;
	for (int i = 0; i < N; i++) {
		if (res[i] < 0 || res[i] >= N) {
			assert(false);
		}
		st.insert(res[i]);
	}
	if (st.size() != N) assert(false);

	int score = 0;
	for (int i = 0; i < M; i++) {
		if (res[edges[i].first] > res[edges[i].second]) {
			score++;
		}
	}
	
	cout << score << endl;
	return 0;
}