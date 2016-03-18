#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin >> n;
	cout << right;
	while (n){
		int r = 1, r0 = 1;
		for (int i = 0; i<n; i++){
			r = r0;
			r0 *= 2;
			for (int j = 0; j<n; j++){
				cout << right << setw(1+(int)((2*n-2)*0.30102999566)) << r<<(j==(n-1)?"":" ");
				r *= 2;
			}
			cout << endl;
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}