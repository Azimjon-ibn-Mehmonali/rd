
// Problem : A. Sequence with Digits
// Contest : Codeforces - Codeforces Round #643 (Div. 2)
// URL : https://codeforces.com/contest/1355/problem/A
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

ii kkr(ll n) {
	int ka, ki;
	ka = -1;
	ki = 10;

	int r;
	while (n) {
		r = n % 10;
		ka = max(ka, r);
		ki = min(ki, r);
		n /= 10;
	}

	return {ka, ki};
}

int main() {
	int t;
	cin >> t;
	// xatop(kkr(950).F);
	// xatop(kkr(950).S);
	while (t--) {
		ll a1, a2, a3, k;
		cin >> a1 >> k;

		a2 = a1;
		while (k--) {
			ii kk = kkr(a2);
			a3 = a2 + kk.F * kk.S;
			a1 = a2;
			a2 = a3;

			if (kk.S == 0) {
				a1 = a2;
				break;
			}
		}

		cout << a1 << endl;
	}

	return 0;
}
