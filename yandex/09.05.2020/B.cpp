
// Problem : B. Business
// Contest : Yandex - Finals
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>
#include <stdio.h>

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
	string s;
	cin >> s;

	sort(rALL(s));

	int ry = 0;
	for (char c : s) ry += c - 48;

	ry %= 3;

	bool b = 0;
	if (ry) {
		for (int i = s.size() - 1; i >= 0; i--) {
			if ((s[i] - 48) % 3 == ry) {
				b = 1;
				s.erase(i, 1);
				break;
			}
		}
	}
	// debug(ry)
	if (!b && ry) {
		for (int i = s.size() - 1; i >= 0; i--) {
			if (stoi(s.substr(i - 1, 2)) % 3 == ry) {
				b = 1;
				s.erase(i - 1, 2);
				break;
			}
		}
	}

	if (s.empty()) {
		cout << -1 << endl;
		return 0;
	}

	int i = 0;
	while (!s.empty() && s[0] == '0') s.erase(0, 1);

	if (s.empty()) s = "0";
	// debug(s)
	// debug(b)
	if (b || ry == 0)
		cout << s << endl;
	else
		cout << -1 << endl;

	return 0;
}
