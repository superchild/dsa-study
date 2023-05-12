#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int absMultiply(int a, int b) {
    int result = 0;
    while (b) {
        if (b & 1) {
            result += a;
        }

        b = b >> 1;
        a = a << 1;
    }

    return result;
}

int multiply(int a, int b) {
    int base = max(abs(a), abs(b));
    int multiply = min(abs(a), abs(b));
    int sign = 1;
    if (a == 0 || b == 0) {
        return 0;
    }

    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        sign = 1;
    } else {
        sign = -1;
    }

    int result = absMultiply(base, multiply);
    return result *= sign;
}

int main() {
    assert(multiply(3, 5) == 3*5);
    assert(multiply(3, -5) == 3*(-5));
    assert(multiply(-3, 5) == (-3)*5);
    assert(multiply(-3, -5) == (-3)*(-5));
    assert(multiply(4, 8) == 4*8);
    assert(multiply(100, 123) == 100*123);
}