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
string itos(int x) {
	string res;
	while (x > 0) {
		res.push_back((x % 10) + '0');
		x /= 10;
	}
	reverse(res.begin(), res.end());
	if (res.size() == 0) res = "0";
	return res;
}
void makeTestCase(int seed) {
	rnd.seeding(seed);
	int N = 100000;
	vector<int> X(N);
	vector<int> Y(N);
	for (int i = 0; i < N; i++) {
		X[i] = rnd.nextInt(1 << 15);
		Y[i] = rnd.nextInt(1 << 15);
	}
	cout << N << "\n";
	for (int i = 0; i < N; i++) {
		cout << X[i] << " " << Y[i] << "\n";
	}
}
int main(int argc, char *argv[]) {
	int seed = stoi(argv[1]);
	makeTestCase(seed);
	return 0;
}