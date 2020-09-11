
// Problem: E - Coprime
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

int p[1000010], t[1000010];

signed main() {
	TEZ;

	int n;
	cin >> n;

	vi a(n);
	int gc = 0;
	bool pr = 1;
	for (int &i : a) {
		cin >> i, gc = gcd(gc, i);

		if (p[i] && i != 1) {
			pr = 0;
		}

		p[i] = 1;
	}

	memset(t, 1, sizeof(t));

	t[0] = t[1] = 0;

	for (int i = 2; i <= 1000005; i++) {
		if (t[i]) {
			bool ish = 0;
			for (int j = i; j <= 1000005; j += i) {
				t[j] = 0;
				if (p[j]) {
					if (ish) {
						pr = 0;
						i = 2e7;
						break;
					} else {
						ish = 1;
					}
				}
			}
		}
	}

	if (pr)
		cout << "pairwise coprime" << endl;
	else if (gc == 1)
		cout << "setwise coprime" << endl;
	else
		cout << "not coprime" << endl;

	return 0;
}
