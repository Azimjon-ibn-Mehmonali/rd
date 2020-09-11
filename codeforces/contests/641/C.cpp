
// Problem : C. Orac and LCM
// Contest : Codeforces - Codeforces Round #641 (Div. 2)
// URL : https://codeforces.com/contest/1350/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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

int dar(int a, int b) {
	if (b == 0) return 1;

	if (b & 1) return a * dar(a, b - 1);

	int jv = dar(a, b / 2);

	return sqr(jv);
}

int main() {
	int n;
	cin >> n;

	vi a(n);
	for (int &i : a)
		sc("%d", &i);

	int tub[200010];
	memset(tub, -1, sizeof(tub));
	tub[0] = tub[1] = 1;
	for (int i = 2; i <= 200010; i++) {
		if (tub[i] == -1) {
			for (int j = i; j <= 200010; j += i)
				tub[j] = i;
		}
	}

	map<ii, int> jtb;
	for (int i = 0; i < n; i++) {
		int t = a[i];
		map<int, int> tb;
		while (t > 1) {
			tb[tub[t]]++;
			t /= tub[t];
		}

		for (auto _i : tb) {
			for (int k = _i.S; k >= 1; k--)
				jtb[{_i.F, k}]++;
		}
	}

	ll jv = 1;
	for (auto it = jtb.begin(); it != jtb.end(); it++) {
		if (it->S == n || it->S == n - 1) {
			while (jv % it->F.F == 0)
				jv /= it->F.F;
			jv *= dar(it->F.F, it->F.S);
		}
	}
	// cout << jtb[{2, 3}] << endl;
	// cout << jtb[{5, 1}] << endl;
	cout << jv << endl;

	return 0;
}
