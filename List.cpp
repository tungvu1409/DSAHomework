#include <iostream>

using namespace std;

struct List{
	int *a;
	int size;
	int size_max;
	
	List(int size_max = 100){
		this->size_max = size_max;
		size = 0;
		a = new int [size_max];
	}
	// chen 1 phan tu vao dau danh sach; (do phuc tap O(n) )  
	void insertFirst(int x){
		if(size == size_max) {
			cout << "List is full";
			return;
		}
		for(int i = size; i > 0; i--){
			a[i] = a[i - 1];
		}
		a[0] = x;
		size++;
	}
	// chen 1 phan tu vao cuoi danh sach; ( do phuc tap 0(1) )
	void insertLast(int x) {
		if(size == size_max) {
			cout << "List is full";
			return;
		}
		a[size] = x;
		size++;
	}
	// chen 1 phan tu vao vi tri bat ki trong danh sach (do phuc tap o(n) vi truong hop xau nhat la chen vao dau danh sach)

	void insertAt(int x, int k){
		if(size == size_max){
			cout << "List is full";
			return;
		}
		if(k < 0 || k > size_max){
			cout << "vi tri k hop le";
			return;
		}
		for(int i = size; i > k; i--){
			a[i] = a[i - 1];
		}
		a[k] = x;
		size++;
	}
	
	// xoa phan tu o dau danh sach (Do phuc tap o(n) vi truong hop xau nhat phai dich het cac ptu sang trai) 
	void deleteFirst() {
		if(size == 0) {
			cout << "khong xoa duoc, danh sach rong";
			return;
		}
		for(int i = 0; i < size - 1; i++){
			a[i] = a[i + 1];
		}
		size--;
	}
	// xoa phan tu o cuoi danh sach  ( do phuc tap 0(1) )
	void deleteLast() {
		if(size == 0) {
			cout << "khong xoa duoc, danh sach rong";
			return;
		}
		size--;
	}
	// xoa phan tu o vi tri bat ki trong danh sach; (do phuc tap o(n) vi truong hop xau nhat la xoa o dau danh sach)
	void deleteAt(int k) {
		if(size == 0) {
			return;
		}
		if(k < 0 || k >= size) {
			return;
		}
		for(int i = k; i < size - 1; i++){
			a[i] = a[i + 1];
		}
		size--;
	}
	// duyet xuoi;
	void print() {
        for (int i = 0; i < size; i++) cout << a[i] << " ";
        cout << endl;
    }
    // duyet nguoc;
    void printNguoc() {
    	for(int i = size - 1; i >= 0; i--) {
    		cout << a[i] << " ";
		}
		cout << endl;
	}
    // truy cap phan tu vi tri thu k;
    int getAt(int k){
    	if(k < 0 || k >= size){
    		return -1;
		}
		return a[k];
	}
	~List() {
        delete[] a;
    }
};
int main(){
	List list(100);
	list.insertFirst(10);
	list.insertFirst(100);
	list.insertLast(1000);
	list.insertLast(1001);
	list.insertAt(99, 2);
	list.deleteFirst();
	list.deleteLast();
	list.deleteAt(2);
	list.print();
	list.printNguoc();
	cout << "Phan tu o vi tri 0: " << list.getAt(0) << endl;
}
