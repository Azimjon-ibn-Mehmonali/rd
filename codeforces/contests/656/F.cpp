#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t != 0) {
		long long int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		if (arr[1] == arr[2]) {
			cout << "YES" << endl;
			cout << arr[0] << " " << arr[0] << " " << arr[2] << endl;
		} else {
			cout << "NO" << endl;
		}
		t--;
	}
	return 0;
}