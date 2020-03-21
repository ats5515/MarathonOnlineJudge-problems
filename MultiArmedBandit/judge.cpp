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
class XorShift {
   public:
	unsigned int x, y, z, w;
	double nL[65536];

	XorShift() {
		init();
	}

	void init() {
		x = 314159265;
		y = 358979323;
		z = 846264338;
		w = 327950288;
		double n = 1 / (double)(2 * 65536);
		for (int i = 0; i < 65536; i++) {
			nL[i] = log(((double)i / 65536) + n);
		}
	}

	inline void seeding(int seed) {
		x = 314159265;
		y = 358979323;
		z = 846264338;
		w = ((seed + 1) * (long long)327950288) % 1000000007;
		for (int i = 0; i < seed % 100; i++) next();
	}

	inline unsigned int next() {
		unsigned int t = x ^ x << 11;
		x = y;
		y = z;
		z = w;
		return w = w ^ w >> 19 ^ t ^ t >> 8;
	}

	inline double nextLog() {
		return nL[next() & 0xFFFF];
	}

	inline int nextInt(int m) {
		return (int)(next() % m);
	}

	int nextInt(int min, int max) {
		return min + nextInt(max - min + 1);
	}

	inline double nextDouble() {
		return (double)next() / ((long long)1 << 32);
	}
};
XorShift rnd;
int main(int argc, char *argv[]) {
	rnd.seeding(stoi(argv[1]));
	ofstream ofs_score(argv[2]);
	string _;
	int N = 50;
	int T = 10000;
	cout << N << " " << T << '\n'
		 << flush;
	vector<double> P(N);
	double mn = 0.2;
	double mx = 0.8;
	for (int i = 0; i < N; i++) {
		P[i] = mn + (((mx - mn) * i) / (N - 1));
	}
	for (int i = 1; i < N; i++) {
		swap(P[i], P[rnd.nextInt(i + 1)]);
	}
	int score = 0;
	for (int i = 0; i < T; i++) {
		int a;
		cin >> a;
		assert(a >= 0 && a < N);
		int b = rnd.nextDouble() < P[a] ? 1 : 0;
		score += b;
		cout << b << '\n'
			 << flush;
	}
	ofs_score << score << endl;
	return 0;
}