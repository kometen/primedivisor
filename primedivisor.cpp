#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

int prime(int x, int b, int n) {
	auto loop_prime_divisor = true;
	for (int s = x; s <= b && loop_prime_divisor; ++s) {
		if (n % s == 0) {
			if (s <= (n / s)) {
				cout << "n = s * t : " << n << " = " << s << " * " << (n / s) << endl;
				prime(x, b, (n / s));
				loop_prime_divisor = false;
			}
		}
	}
	return n;
}

int main(int argc, char const *argv[]) {
	auto is_prime = true;
	auto n = 245;
	auto b = static_cast<int>(sqrt(n));

	// Start with three as divisor if n > 2 to save one small step
	auto x = 2;
	if (n > 2) {
		x = 3;
	}

	cout << "n: " << n << ", b: " << b << endl;

	prime(x, b, n);

	return 0;
}