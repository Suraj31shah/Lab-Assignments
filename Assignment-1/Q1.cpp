#include <iostream>
#include <vector>
using namespace std;
int findMax(int A[], int n) {
    int st=0,end=n-1,mid;
    while(st<=end) {
        mid=st+(end-st)/2; 
        if(A[mid-1]>A[mid]) {
            end=mid-1;
        }
        else if(A[mid+1]>A[mid]) {
            st=mid+1;
        }
        else {
            return A[mid];
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    cout << "The maximum number in the array is: " << findMax(A,n);
}
