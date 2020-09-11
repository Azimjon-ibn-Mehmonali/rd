
// Problem : A. Astronomy
// Contest : Yandex - Finals
// Memory Limit : 512 MB
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
#define debug(a) cout << #a << " = " << a << endl;
#define jsatr debug(__LINE__)
#define INF 1000000000
#define mod 1000000007

int main()
{
	int n, s;
	cin >> n >> s;
	
	vi a(n);
	int yi = 0;
	for (int &i: a)
		cin >> i, yi += i;
	
	if (s < yi) {
		cout << 1 << endl;
	}
	else if (yi < s)
		cout << -1 << endl;
	else
		cout << 0 << endl;
	
    return 0;
}
