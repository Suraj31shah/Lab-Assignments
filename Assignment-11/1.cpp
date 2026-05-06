#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot=a[high];
    int i=low-1;
    for (int j=low; j<high; j++) {
        if (a[j]<pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

int quickSort(int a[], int low, int high, int k) {
    if (low<high) {
        int pivot=partition(a, low, high);

        if (pivot==k) {
            return a[pivot];
        }

        else if (pivot>k) {
            return quickSort(a, low, pivot-1, k);
        }

        else {
            return quickSort(a, pivot+1, high, k);
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
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Array: ";
    printArray(arr, n);

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "The kth smallest element is: " << quickSort(arr, 0, n-1, k-1);
}