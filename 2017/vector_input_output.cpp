#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << "\n";

	return 0;
}