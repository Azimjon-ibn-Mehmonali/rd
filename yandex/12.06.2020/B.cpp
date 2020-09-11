
// Problem : B. 30 ham omadli son
// Contest : Yandex - Uyda qoling - zavq oling #3
// URL : https://contest.yandex.ru/contest/18414/problems/B/
// Memory Limit : 64 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define pb push_back
#define endl "\n"

#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

int main() {
	TEZ;

	string s;
	cin >> s;

	SORT(s);
	REV(s);

	int ry = 0;
	for (char c : s) {
		ry += c - '0';
	}

	if (ry % 3 == 0 && s.back() == '0')
		cout << s << endl;
	else
		cout << -1 << endl;

	return 0;
}
