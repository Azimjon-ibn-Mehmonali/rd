
// Problem : Chef and Recipe
// Contest : CodeChef - May Cook-Off 2020 Division 2
// URL : https://www.codechef.com/COOK118B/problems/CHEFRECP
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

void yechim() {
	int n;
	cin >> n;

	vi a(n);
	for (int &i : a)
		cin >> i;
	a.pb(INF);
	int j;
	map<int, int> mas;
	set<int> ms;
	for (int i = 0; i < n;) {
		j = 0;
		while (a[i] == a[i + j])
			j++;

		if (mas[a[i]] || ms.count(j)) {
			cout << "NO\n";
			return;
		}
		mas[a[i]] = j;
		ms.insert(j);
		i += j;
	}
	cout << "YES\n";
}
int main() {
	int t;
	cin >> t;

	while (t--)
		yechim();

	return 0;
}
