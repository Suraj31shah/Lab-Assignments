#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n) {
    int max=*max_element(arr, arr+n);
    
    int count[max+1]={0};
    for (int i=0; i<n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Array: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Sorted Array using Counting Sort: ";
    printArray(arr, n);
}