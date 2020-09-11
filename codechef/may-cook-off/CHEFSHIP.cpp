
// Problem : Chef, Chefina and Their Friendship
// Contest : CodeChef - May Cook-Off 2020 Division 2
// URL : https://www.codechef.com/COOK118B/problems/CHEFSHIP
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

void bajar() {
	string s;
	cin >> s;

	int n = s.size();
	int b = (n - 2) / 2;
	int jv = 0;
	for (int i = 1; i <= b; i++) {
		string q1 = s.substr(0, i);
		string q2 = s.substr(i, i);

		int gh = (n - 2 * i) / 2;
		string q3 = s.substr(2 * i, gh);
		string q4 = s.substr(2 * i + gh, gh);
		// xatop(q1);
		// xatop(q2);
		// xatop(q3);
		// xatop(q4);
		if (q1 == q2 && q3 == q4) jv++;
	}

	cout << jv << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
		bajar();

	return 0;
}
