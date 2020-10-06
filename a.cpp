#include <iostream>
using namespace std;
int divide86400(string s) {
	int i = 0, a = 0;
	while (i < s.length()) {
		a = a * 10 + (s[i] - '0');
		a = a % 86400;
		i++;
	}
	return a;
}
int main() {
	string s;
	int a;
	cin >> s;
	a = divide86400(s);
	cout << a / 3600 << ":";
	a = a % 3600;
	if (a / 60 < 10)
		cout << "0" << a / 60 << ":";
	else
		cout << a / 60 << ":";
	a = a % 60;
	if (a < 10)
		cout << "0" << a;
	else
		cout << a;
}