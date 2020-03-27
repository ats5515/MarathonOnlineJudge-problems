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
double calcWinRate(double x, double y) {
	return 1.0 / (pow(10, (y - x) / 400) + 1);
}
int main(int argc, char *argv[]) {
	rnd.seeding(stoi(argv[1]));
	ofstream ofs_score(argv[2]);
	string _;
	int N = 100;
	vector<double> rate(N);
	for (int i = 0; i < N; i++) {
		rate[i] = rnd.nextDouble() * 1000;
	}
	int T = 10000;
	cout << N << " " << T << '\n'
		 << flush;
	int score = 0;
	for (int i = 0; i < T; i++) {
		int a, b;
		do {
			a = rnd.nextInt(N);
			b = rnd.nextInt(N);
		} while (a == b);
		cout << a << " " << b << '\n'
			 << flush;
		char X, Y;
		cin >> X;
		assert(X == '>' || X == '<');
		double winrate = calcWinRate(rate[a], rate[b]);
		if (rnd.nextDouble() < winrate) {
			Y = '>';
		} else {
			Y = '<';
		}
		if (X == Y) score++;
		cout << Y << '\n'
			 << flush;
	}

	ofs_score << score << endl;
	return 0;
}