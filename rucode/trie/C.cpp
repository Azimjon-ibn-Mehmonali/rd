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

const int N = 5000000;

map<int, int> a[N];
bool t[N];
int u[N];
int o = 1;
int jv = 0;

void insert(string& s) {
	int n = s.size();
	for (int j = 0; j < n; j++) {
		int in = 0;
		for (int i = j; i < n; i++) {
			if (a[in][s[i]] == 0)
				in = a[in][s[i]] = o++;
			else
				in = a[in][s[i]];
			if (t[in] == 0) {
				jv++;
				t[in] = 1;
			}
		}
	}
}

signed main() {
	TEZ;

	string s;
	cin >> s;

	insert(s);
	cout << jv << endl;

	return 0;
}
