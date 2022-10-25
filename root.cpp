#include <iostream>
using namespace std;

float root(int N, int P) {
    // binary search
    // O(log N)
    int left = 0;
    int right = N;
    float ans = 0.0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid*mid == N) {
            return (float) mid;
        }
        else if (mid*mid < N) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    // linear search
    // O(9P)
    float inc = 0.1;
    for (int place = 1; place <= P; place++) {
        
        while (ans*ans <= N) {
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc / 10;
    }

    // total execution time: O(log N  +  9P)
    return ans;
}

int main(void) {
    int N, P;
    cin >> N >> P;

    cout << root(N, P) << endl;

    return 0;
}