#include <iostream>
using namespace std;

struct MaxHeap {
    int a[100]; 
    int n;       

    MaxHeap() {
        n = 0;
    }

	// kiem tra rong
    bool isEmpty() {
        return n == 0;
    }
	
	// tra ve kich thuoc hien tai trong heap
    int size() {
        return n;
    }

	// tra ve phan tu lon nhat ( root )
    int max() {
        if (isEmpty()) {
            cout << "Heap rong!\n";
            return -1;
        }
        return a[1]; 
    }

	// them 1 phan tu 
    void insert(int value) {
        n++;
        a[n] = value; 
        
        int i = n;
        while (i > 1 && a[i/2] < a[i]) {
            swap(a[i], a[i/2]);
            i /= 2; 
        }
    }

	//xoa phan tu lon nhat(root)
    int delMax() {
        if (isEmpty()) {
            cout << "Heap rong!\n";
            return -1;
        }

        int maxVal = a[1];
        a[1] = a[n]; 
        n--;

        int i = 1;
        while (true) {
            int l = 2 * i;
            int r = 2 * i + 1;
            int newMax = i;
            if (l <= n && a[l] > a[newMax])
                newMax = l;
            if (r <= n && a[r] > a[newMax])
                newMax = r;
            if (newMax != i) {
                swap(a[i], a[newMax]);
                i = newMax; 
            } 
			else {
				break;
			}
        }
        return maxVal;
	}

 
    void printHeap() {
        if (isEmpty()) {
            cout << "Heap rong!\n";
            return;
        }
        cout << "Cac phan tu trong heap: ";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;

    pq.insert(20);
    pq.insert(5);
    pq.insert(30);
    pq.insert(10);
    pq.insert(25);

    pq.printHeap();  

    cout << "Max hien tai: " << pq.max() << endl;
    cout << "Kich thuoc heap: " << pq.size() << endl;

    cout << "Xoa max: " << pq.delMax() << endl;
    pq.printHeap();

    cout << "Xoa max tiep: " << pq.delMax() << endl;
    pq.printHeap();

    cout << "Heap con rong khong? " << (pq.isEmpty() ? "Co" : "Khong") << endl;
	
}

