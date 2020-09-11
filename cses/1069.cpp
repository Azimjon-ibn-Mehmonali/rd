
// Problem : Repetitions
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1069
// Memory Limit : 512 MB
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

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const double PI = 3.1415926535897932384626433832795;

int main() {
	TEZ;

	string s;
	cin >> s;

	int jv, hh;
	jv = -INF;
	hh = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1])
			hh++;
		else
			jv = max(jv, hh), hh = 1;
	}

	jv = max(jv, hh);

	cout << jv << endl;

	return 0;
}
