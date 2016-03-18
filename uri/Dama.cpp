#include<iostream>
using namespace std;
int main(){
	int x1, x2, y1, y2;
	while (true){
		cin >> x1 >> y1 >> x2 >> y2;
		if (!(x1||x2||y1||y2)){
			break;
		}
		if (x1 == x2&y1 == y2){
			cout << 0 << endl;
			continue;
		}
		if ((x1 == x2&&y1 != y2 )||( x1!= x2&&y1 == y2)){
			cout << 1 << endl;
			continue;
		}
		if (x1 - x2 == y1 - y2 || x1 - x2 == y2 - y1){
			cout << 1<< endl;
			continue;
		}

		cout << 2 << endl;
	}
	return 0;
}