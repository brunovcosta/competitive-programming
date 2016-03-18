#include<iostream>
using namespace std;
int main(){
	int w0, x0, y0, z0, w1, x1, y1, z1, wf, xf, yf, zf;
	long int m0,m1,delta;
	cin.ignore(256, ' '); cin >> w0; 
	cin >> x0; cin.get(); cin.get();
	cin >> y0; cin.get(); cin.get();
	cin >> z0;
	cin.ignore(256, ' '); cin >> w1;
	cin >> x1; cin.get(); cin.get();
	cin >> y1; cin.get(); cin.get();
	cin >> z1;
	m0 = z0 + 60 * y0 + 60 * 60 * x0 + 60 * 60 * 24 * w0;
	m1 = z1 + 60 * y1 + 60 * 60 * x1 + 60 * 60 * 24 * w1;
	delta = m1 - m0;
	wf = delta / (24*60*60);
	delta -= wf * 24*60*60;
	cout << wf << " dia(s)"<<endl;
	xf = delta / (60*60);
	delta -= xf * 60*60;
	cout << xf << " hora(s)" << endl;
	yf = delta / 60;
	delta -= yf * 60;
	cout << yf << " minuto(s)" << endl;
	zf = delta;
	cout << zf << " segundo(s)" << endl;

}