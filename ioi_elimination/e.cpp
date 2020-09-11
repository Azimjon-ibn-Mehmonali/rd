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

vi so;
string x;
int n, l, r, k;
int jv = 0;
void c(int o) {
	if (o == n) {
		if (so.size() != k) return;
		xtp(so);
		SORT(so);
		bool ha = 1;
		for (int i = 1; i < k; i++) {
			int e = llabs(so[i] - so[i - 1]);
			ha &= (l <= e && e <= r);
		}

		jv += ha;
		return;
	}

	if (o > n)
		return;

	for (int i = o; i < n; i++) {
		string q = (x.substr(o, i - o + 1));
		
		if (q != "0" && q[0] == '0')
			continue;
		so.pb(stoll(q));
//		xtp(i);
//		xtp(q);
		c(i + 1);
		so.pop_back();
	}
}

void f() {
	cin >> x >> l >> r >> k;
jv = 0;
	n = x.size();
	so.clear();

	c(0);

	cout << jv << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
