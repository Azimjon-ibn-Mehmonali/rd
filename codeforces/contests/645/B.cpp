
// Problem : B. Maria Breaks the Self-isolation
// Contest : Codeforces - Codeforces Round #645 (Div. 2)
// URL : https://codeforces.com/contest/1358/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define sqr(x) (x) * (x)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define sc scanf
#define pr printf
#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)
#define INF 1000000000
#define mod 1000000007

const double PI = 3.1415926535897932384626433832795;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vi a(n);
		for (int &i : a)
			cin >> i;

		SORT(a);
		a.pb(INF);

		int jv = -INF;

		for (int i = 0; i < n; i++) {
			if (a[i] <= i + 1) jv = max(i + 2, jv);
		}

		if (jv == -INF) jv = 1;

		cout << jv << endl;
	}

	return 0;
}
