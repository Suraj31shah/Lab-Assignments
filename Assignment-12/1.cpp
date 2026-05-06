#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<int>& arr, int bucketCount) {
    if (arr.empty()) {
        return;
    }

    int min_value=*min_element(arr.begin(), arr.end());
    int max_value=*max_element(arr.begin(), arr.end());

    vector<vector<int>> buckets(bucketCount);

    for (int num: arr) {
        int index=(num-min_value)*bucketCount/(max_value-min_value+1);
        buckets[index].push_back(num);
    }

    arr.clear();
    for (auto bucket: buckets) {
        sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

int main() {
    vector<int> arr={12, 45, 33, 87, 56, 9, 11, 7, 67};
    int bucketCount=7;

    cout << "Original Array: ";
    for (int num: arr) {
        cout << num << " ";
    }
    cout << endl;

    bucketSort(arr, bucketCount);

    cout << "Sorted Array: ";
    for (int num: arr) {
        cout << num << " ";
    }
    cout << endl;
}