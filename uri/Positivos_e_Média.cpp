#include<iostream>
using namespace std;
int main(){
	int n=0;
	double a, b, c, d, e, f,soma = 0;
	cin >> a >> b >> c >> d >> e >> f;
	if (a>0){
		n++;
		soma += a;
	}
	if (b>0){
		n++;
		soma += b;
	}
	if (c>0){
		n++;
		soma += c;
	}
	if (d>0){
		n++;
		soma += d;
	}
	if (e>0){
		n++;
		soma += e;
	}
	if (f>0){
		n++;
		soma += f;
	}
	cout << fixed;
	cout.precision(1);
	cout << n << " valores positivos" << endl;
	if (n>0)
		cout << soma / n<<endl;
	return 0;
}
