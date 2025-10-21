#include <iostream>

using namespace std;

void heapify(int a[], int n, int i) {
    int newMax = i;        
    int l = 2 * i + 1;   
    int r = 2 * i + 2;  
    if (l < n && a[l] > a[newMax])
        newMax = l;
    if (r < n && a[r] > a[newMax])
        newMax = r;
    if (newMax != i) {
        swap(a[i], a[newMax]);
        heapify(a, n, newMax); 
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]); 
        heapify(a, i, 0);   
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {5, 3, 8, 4, 1, 9, 2};
    int n = 7;
    cout << "ban dau: ";
    printArray(a, n);
    heapSort(a, n);
    cout << "sau khi heap sort: ";
    printArray(a, n);

}

