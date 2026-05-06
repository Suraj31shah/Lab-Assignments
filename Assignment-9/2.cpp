#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int temp[high-low+1];
    int i=low;
    int j=mid+1;
    int k=0;

    while (i<=mid && j<=high) {
        if (arr[i]<=arr[j]) {
            temp[k++]=arr[i++];
        }

        else {
            temp[k++]=arr[j++];
        }
    }

    while (j<=high) {
        temp[k++]=arr[j++];
    }

    while (i<=mid) {
        temp[k++]=arr[i++];
    }

    for (k=0, i=low; i<=high; k++, i++) {
        arr[i]=temp[k];
    }
}

void mergeSort(int arr[] , int low, int high) {
    if (low<high) {
        int mid=low+(high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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

    cout << "Original Array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    printArray(arr, n);
}