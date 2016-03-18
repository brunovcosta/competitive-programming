#include<iostream>
using namespace std;
int main(){
	double r, pi = 3.14159;
	cin >> r;
	cout << fixed;
	cout.precision(4);
	cout <<"A="<< r*pi*r<<endl;
	return 0;
}