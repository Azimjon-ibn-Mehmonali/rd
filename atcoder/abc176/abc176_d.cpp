
// Problem: D - Wizard in Maze
// Contest: AtCoder - AtCoder Beginner Contest 176
// URL: https://atcoder.jp/contests/abc176/tasks/abc176_d
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

int s[1005][1005];

signed main() {
	TEZ;

	int h, w;
	cin >> h >> w;

	int ch, cw;
	cin >> ch >> cw;

	int dh, dw;
	cin >> dh >> dw;

	for (int i = 1; i <= h; i++) {
		string r;
		cin >> r;

		for (int j = 1; j <= w; j++)
			s[i][j] = r[j - 1] == '.';
	}

	return 0;
}
