#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double sum, a, b;
	do
	{
		cin >> a >> b;

	} while (0>=a || b>=pow(10, 19));
	sum = a + b;
	cout << sum;
	return 0;
}
