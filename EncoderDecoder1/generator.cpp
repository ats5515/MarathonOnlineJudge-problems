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
void makeTestCase(int seed) {
	rnd.seeding(seed);
	int N = 100;
	vector<vector<int> > X(N, vector<int>(N, 0));
	for (int loop = 0; loop < 500; loop++) {
		int center_x = rnd.nextInt(N);
		int center_y = rnd.nextInt(N);
		int radius = rnd.nextInt(N / 6);
		int val = rnd.nextInt(4);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((center_x - i) * (center_x - i) +
						(center_y - j) * (center_y - j) <= radius * radius) {
							X[i][j] = val;
				}
			}
		}
	}
	cout << "encoder" << endl;
	cout << N << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << X[i][j];
		}
		cout << endl;
	}
}
int main(int argc, char *argv[]) {
	int seed = stoi(argv[1]);
	makeTestCase(seed);
	return 0;
}