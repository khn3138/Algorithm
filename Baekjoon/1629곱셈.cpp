#include <iostream>
#include <cmath>
using namespace std;

int A, B, C;

long long f(int b) {
	if (b == 1) return A % C;
	long long temp = f(b / 2) % C;
	if (b % 2 == 0) {//Â¦¼ö
		return temp * temp % C;
	}
	else {
		return temp * temp % C * A % C;
	}
}

int main() {
	scanf("%d %d %d", &A, &B, &C);

	printf("%lld", f(B));

	return 0;
}