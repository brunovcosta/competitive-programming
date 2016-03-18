#include<iostream>
using namespace std;
int main(){
	while (true){
		int a, b, c;
		cin >> a;
		if (cin.eof())
			break;
		cin >> b >> c;
		if ((!a) && (!b) && (!c))cout << "*" << endl;
		if ((!a) && (!b) && (c))cout << "C" << endl;
		if ((!a) && (b) && (!c))cout << "B" << endl;
		if ((!a) && (b) && (c))cout << "A" << endl;
		if ((a) && (!b) && (!c))cout << "A" << endl;
		if ((a) && (!b) && (c))cout << "B" << endl;
		if ((a) && (b) && (!c))cout << "C" << endl;
		if ((a) && (b) && (c))cout << "*" << endl;
	}
	return 0;
}