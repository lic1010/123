#include<iostream>
#include<string>
using namespace std;
template <typename T>
void f(int n,int q) {
	T key;
	T* target = new T[n];//�ʺA�}�C
	for (int i = 0; i < n;i++) {
		cin >> target[i];
	}
	for (int i = 0; i < q;i++) {
		cin >> key;
		int left = 0, right = n - 1;
		bool found = false;
		while (left <= right) {//�G���j�M�k
			int mid = (left + right) / 2;
			if (target[mid] < key) {
				left = mid + 1;

			}
			else if (target[mid] > key)
			{
				right = mid - 1;

			}
			else
			{
				cout << mid << '\n';
				found = true;
				break;
			}
		}
		if(!found)cout << -1 << '\n';
	}
	delete[]target;
}

int main() {
	char t;
	int n=0, q=0;
	while (cin >> t >> n >> q) {
		if (t == 'i') {
			f<int>(n, q);
		}
		if (t == 's') {
			f<string>(n, q);
		}
	}
	return 0;
}