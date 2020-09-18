
// Problem: A. Okabe and Boxes
// Contest: Codeforces - Practice #last
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/295403/problem/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int df[333333];

signed main() {
	TEZ;

	int n;
	cin >> n;

	string s;
	int t;

	vi a;
	int jv = 0;

	int o = 1;
	set<int> q;
	bool er = 1;
	vi h;
	for (int i = 0; i < 2 * n; i++) {
		cin >> s;

		if (s == "add") {
			cin >> t;
			df[t] = i;
			h.pb(i);
			// a.pb(t);
			q.insert(t);
			if (q.find(t) != q.begin()) {
				er = 0;
			}
		} else {
			if (df[o] == h.back()) {
				h.pop_back();
				q.erase(q.begin());
				o++;
				continue;
			}
			if (!er) {
				jv++;
				er = 1;
			}
			q.erase(q.begin());
			o++;
		}
	}

	cout << jv << endl;

	return 0;
}
