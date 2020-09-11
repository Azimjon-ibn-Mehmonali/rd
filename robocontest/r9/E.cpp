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

	int t;
	cin >> t;

	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;

		string s;

		int i, j;
		i = j = 0;

		int ss1, ss2;
		ss1 = s1.size();
		ss2 = s2.size();
		while (i < ss1 && j < ss2) {
			if (s1[i] < s2[j])
				cout << s1[i], i++;
			else
				cout << s2[j], j++;
		}

		while (i < ss1)
			cout << s1[i], i++;

		while (j < ss2)
			cout << s2[j], j++;

		cout << endl;
	}

	return 0;
}
