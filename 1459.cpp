#include <iostream>

using namespace std;

long long x, y, d1, d2;

int main() {
    cin >> x >> y >> d1 >> d2;
    long long answer = 0;
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if (d1 * 2 < d2) {
        answer += (x + y) * d1;
    } else if (2 * d1 > d2 * 2) {
        if ((x + y) % 2 == 0) answer += (y) * d2;
        else answer += ((y - 1) * d2 + d1);
    } else {
        answer += x * d2;
        answer += (y - x) * d1;
    }
    cout << answer << endl;
}