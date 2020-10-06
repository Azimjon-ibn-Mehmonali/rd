// Muallif: Azimjon Mehmonali o'g'li

//=========================================================

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//=========================================================
#ifdef DEBUG
#define xtp xtp1
#else
#define xtp(x)
#endif
//=========================================================

#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define pb push_back
#define endl "\n"

#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(ALL(a))
#define rSORT(a) sort(rALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

const int N = 131072;

int ka[2 * N], ki[2 * N];

void init() {
	for (int i = 1; i <= N; i++) {
		int q = i + N - 1;
		ki[q] = ka[q] = ((i * i) % 12345) + ((i * i * i) % 23456);
	}
	for (int i = N - 1; i > 0; i--) {
		ka[i] = max(ka[2 * i], ka[2 * i + 1]);
		ki[i] = min(ki[2 * i], ki[2 * i + 1]);
	}
}

void change(int x, int y) {
	int i = x + N - 1;
	ki[i] = ka[i] = y;
	i /= 2;
	while (i > 0) {
		ka[i] = max(ka[2 * i], ka[2 * i + 1]);
		ki[i] = min(ki[2 * i], ki[2 * i + 1]);
		i /= 2;
	}
}

int kat(int v, int l, int r, int tl, int tr) {
	if (r < tl || tr < l) return -INF;
	if (tl <= l && r <= tr) return ka[v];

	int m = (l + r) / 2;

	return max(kat(2 * v, l, m, tl, tr), kat(2 * v + 1, m + 1, r, tl, tr));
}

int kic(int v, int l, int r, int tl, int tr) {
	if (r < tl || tr < l) return INF;
	if (tl <= l && r <= tr) return ki[v];

	int m = (l + r) / 2;

	return min(kic(2 * v, l, m, tl, tr), kic(2 * v + 1, m + 1, r, tl, tr));
}

signed main() {
	TEZ;

	init();

	int k;
	cin >> k;

	int x, y;
	while (cin >> x >> y) {
		if (x < 0) {
			change(-x, y);
		} else {
			// cout << "-" << kic(1, 1, N, x, y) << endl;
			cout << llabs(kic(1, 1, N, x, y) - kat(1, 1, N, x, y)) << endl;
		}
	}

	return 0;
}
