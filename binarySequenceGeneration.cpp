#include<bits/stdc++.h>
using namespace std;

void genarate_binary_strings(int n, string current_str = "") {
	if (n < 1 || n>20) {
		cout << "Do dai khong hop le!" << endl;
		return;
	}
	if (current_str.length() == n) {
		cout << current_str << endl;
		return;
	}
	genarate_binary_strings(n, current_str + '0');
	genarate_binary_strings(n, current_str + '1');
}

int main() {
	int n;
	cout << "Nhap do dai n: ";
	cin >> n;
	genarate_binary_strings(n);
	return 0;
}