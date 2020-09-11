// Muallif: Azimjon Mehmonali o'g'li

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sc scanf
#define pr printf
#define endl "\n"

#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define sqr(x) ((x) * (x))

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

int main() {
	TEZ;

	int n;
	cin >> n;

	vector<vector<int>> g(n + 1, vector<int>());

	int u;
	for (int i = 1; i <= n; i++) {
		cin >> u;
		u = (u == -1 ? 0 : u);

		g[u].pb(i);
	}

	/*	for (int i = 0; i <= n; i++) {
			cout << i << "bbbbb\n";
			for (int j = 0; j < g[i].size(); j++) {
				cout << g[i][j] << endl;
			}
		}*/

	queue<int> nav;
	nav.push(0);

	vi mas(n + 1, 0);
	// jsatr;
	while (!nav.empty()) {
		int jt = nav.front();
		nav.pop();

		for (int i = 0; i < g[jt].size(); i++) {
			int bt = g[jt][i];
			mas[bt] = mas[jt] + 1;
			nav.push(bt);
		}
	}

	ll jv = 0;
	for (int i = 0; i <= n; i++) {
		// #define xatop(a) cerr << #a << " = " << a << endl;
		xatop(mas[i]);
		jv += mas[i];
	}

	cout << jv << endl;

	return 0;
}
