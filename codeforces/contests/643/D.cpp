
// Problem : D. Game With Array
// Contest : Codeforces - Codeforces Round #643 (Div. 2)
// URL : https://codeforces.com/contest/1355/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define jsatr debug(__LINE__)
#define INF 1000000000
#define mod 1000000007

int main() {
	int n, s;
	cin >> n >> s;

	vi a(n - 1, 1);
	a.pb(s - n + 1);

	if (s + 2 <= 2 * n) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i : a)
			pr("%d ", i);

		pr("\n%d", (a.back() + n) / 2);
	}

	return 0;
}
