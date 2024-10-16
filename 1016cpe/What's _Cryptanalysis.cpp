#include<iostream>
#include<string>
using namespace std;

int main() {
    char a[26] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z'
    };
    int b[26] = {0};
    int x;
    string c,d;
    cin >> x;
    getline(cin,d);
    while (x--) {
        getline(cin, c);
        for (int i = 0; i < c.length(); i++) {
            if (c[i] >= 'a' && c[i] <= 'z') {
                b[c[i] - 'a']++;
            }
            if (c[i] >= 'A' && c[i] <= 'Z') {
                b[c[i] - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (b[i] < b[j]) {
                swap(b[i], b[j]);
                swap(a[i], a[j]);
            }
            if (b[i] == b[j] && a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (b[i] > 0)
            cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}
