#include <iostream>

using namespace std;

float root(int N, int P) {
    // Binary Search
    int left = 0;
    int right = N;
    float ans = 0.0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid * mid == N) return (float) mid;
        else if (mid * mid < N) {
            ans = (float) mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // Linear Search
    float inc = 0.1;
    for (int place = 1; place <= P; place++) {
        while (ans * ans <= N) {
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc / 10.0;
    }
    // Total time of execution: O( log n  +  9P )
    return ans;
}

int main(void) {
    int N, P;
    cin >> N >> P;

    cout << root(N, P) << endl;

    return 0;
}