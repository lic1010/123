#include<iostream>
using namespace std;

void ff(int box[],int size_box) {
	int* new_box = new int[size_box]; //建立新的陣列
	int* a = new_box; //指向新的陣列

	for (int i = 0; i < size_box/2;i++) {//複製
		new_box[i] = box[i];
	}
	for (int b = size_box/2; b < size_box; b++) {//增加值
		cin >> new_box[b];
	}
	for (int i = 0; i < size_box;i++) {
		cout << new_box[i]<<'\n';
	}
	delete[] new_box;
}

int main() {
	int* a;
	int box[2] = {1,2};
	ff(box,2*2);

	return 0;
}