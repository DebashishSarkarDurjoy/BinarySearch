#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int> arr, int k) {
    int left = 0;
    int right = arr.size() - 1;

    int ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == k) {
            ans = mid;
            left = mid + 1;
        }
        else if (arr[mid] > k) {
            right = mid - 1;
        }
        else {
            left = mid - 1;
        }
    }
    return ans;
}

int lower_bound(vector<int> arr, int k) {
    int left = 0;
    int right = arr.size() - 1;

    int ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == k) {
            right = mid - 1;
            ans = mid;
        }
        else if (arr[mid] > k) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int main(void) {
    vector<int> arr = {0,1,1,2,3,3,3,3,3,4,5,5,5,10};
    int k = 1;

    cout << "Frequency count: " << upper_bound(arr, k) - lower_bound(arr, k) + 1 << endl;

    return 0;
}