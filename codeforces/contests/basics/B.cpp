
// Problem : B. Yellow Cards
// Contest : Codeforces - OCS - Round 1 (Basics)
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
#define debug(a) cerr << #a << " = " << a << endl;
#define jsatr debug(__LINE__)
#define INF 1000000000
#define mod 1000000007

int main() {
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;

	if (k1 > k2)
		swap(k1, k2), swap(a1, a2);

	int _n = n;
	_n -= (k2 - 1) * a2;
	_n -= (k1 - 1) * a1;

	int jv1, jv2;

	if (_n <= 0)
		jv1 = 0;
	else {
		jv1 = min(_n, a1 + a2);
	}

	_n = n;

	jv2 = min(n / k1, a1);
	n -= jv2 * k1;

	if (n > 0)
		jv2 += min(n / k2, a2);

	cout << jv1 << " " << jv2 << endl;

	return 0;
}
