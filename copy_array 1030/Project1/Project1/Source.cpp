#include<iostream>
using namespace std;

void ff(int box[],int size_box) {
	int* new_box = new int[size_box]; //�إ߷s���}�C
	int* a = new_box; //���V�s���}�C

	for (int i = 0; i < size_box/2;i++) {//�ƻs
		new_box[i] = box[i];
	}
	for (int b = size_box/2; b < size_box; b++) {//�W�[��
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