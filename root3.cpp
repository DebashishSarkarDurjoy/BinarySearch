#include <iostream>
using namespace std;

float root(int num, int places) {
    int left = 0;
    int right = num;
    float ans = 0.0; 
    while (left <= right) {
        int mid = (left + right) / 2;

        if (mid * mid == num) {
            return (float) num;
        }
        else if (mid * mid > num) {
            right = mid - 1;
        }
        else {
            ans = (float) mid;
            left = mid + 1;
        }
    }

    float inc = 0.1;
    for (int i = 1; i <= places; i++) {
        while (ans * ans <= num) {
            ans += inc;
        }
        ans -= inc;
        inc = inc / 10;
    }

    return ans;
} 

int main(void) {
    int num, dec;
    cin >> num >> dec;

    cout << root(num, dec) << endl;

    return 0;
}