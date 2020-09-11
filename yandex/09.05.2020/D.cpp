
// Problem : D. Drinking Tea
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
	int q1, q2, jv;

	printf("? 1000000\n");
	fflush(stdout);
	flush(cout);
	scanf("%d", &q1);

	printf("? 123\n");
	fflush(stdout);
	scanf("%d", &q2);

	if (q1 == 0)
		jv = 1000000;
	else
		jv = q1;

	printf("! %d\n", jv);
	fflush(stdout);
	flush(cout);

	system("pause");

	return 0;
}
