#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int size, int exp) {
    int base = 10;
    int output[size];
    int count[base] = {0};

    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / exp) % base;
        count[digit]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % base;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size) {
    int maxVal = *max_element(arr, arr + size);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, size, exp);
    }
}

int main() {
    // int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    // int size = sizeof(arr) / sizeof(arr[0]);

    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements: ";
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
