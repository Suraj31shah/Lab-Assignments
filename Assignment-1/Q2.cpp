#include <iostream>
using namespace std;

int countInversion(int A[],int n) {
    int i,j,count=0;

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(A[i]>A[j]) {
                count++;
            }
        }
    }

    return count;
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
    
    cout << "The number of inversions are: " << countInversion(A,n);
}