
// Problem : F. Binary String Reconstruction
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/F
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
#define jsatr xatop(__LINE__)
#define INF 1000000000
#define mod 1000000007

const double PI = 3.1415926535897932384626433832795;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;

		string s;
		int n000 = n0;
		while (n0--)
			s.pb('0');

		if ((n000 && n1 <= 1) || (n1 == 1 && n000 == 0)) s += "0";

		if (n1 > 1) {
			if (n1 % 2 == 0) s.insert(0, "1"), n1--;

			n1 = ceil(n1 / 2.);
			while (n1--)
				s += "01";
		}

		if (s.empty() || ((n2 + n1) && s.back() == '0')) s.pb('1');

		while (n2--)
			s.pb('1');

		cout << s << endl;
	}

	return 0;
}
