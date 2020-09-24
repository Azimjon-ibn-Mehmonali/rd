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

signed main() {
	TEZ;

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	function<int(int, int, int, int)> mas
		= [&](int x1, int y1, int x2, int y2) {
			  return (sqr(x1 - x2) + sqr(y1 - y2));
		  };

	if (mas(x1, y1, x2, y2) == mas(x1, y1, x3, y3)) {
		swap(x2, x1);
		swap(y2, y1);
	}

	if (mas(x1, y1, x2, y2) > mas(x1, y1, x3, y3)) {
		swap(x2, x3);
		swap(y2, y3);
	}

	cout << x1 + x3 - x2 << " " << y1 + y3 - y2 << endl;

	return 0;
}
