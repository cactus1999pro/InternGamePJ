#include<iostream>

using namespace std;

void Factorial(int n) {
	long long int f = 1;
	for (int i = 1; i <= n; i++) {
		f *= i;
	}
	cout << n << "! = " << f << endl;
}
int Enter(int& n) {
	cout << "Enter your number: " << endl;
	cin >> n;
	if (n == 0) {
		cout << "0! = 1" << endl;
	}
	else {
		while (n < 0) {
			cout << "Enter a invalid number: ";
			cin >> n;
		}
	}

	return n;
}
int main() {
	int n;
	Enter(n);
	Factorial(n);
	return 0;
}