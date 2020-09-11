
// Problem : B. Ternary String
// Contest : Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1354/problem/B
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

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int i1, i2, i3;
		i1 = s.find('1');
		i2 = s.find('2');
		i3 = s.find('3');
		if (i1 == -1 || i2 == -1 || i3 == -1) {
			cout << 0 << endl;
			continue;
		}

		int jv = INF;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
				case '1':
					i1 = i;
					break;
				case '2':
					i2 = i;
					break;
				case '3':
					i3 = i;
					break;
			}

			jv = min(jv, max({i1, i2, i3}) - min({i1, i2, i3}) + 1);
		}
		cout << jv << endl;
	}

	return 0;
}
