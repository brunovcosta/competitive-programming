#include<iostream>
#include<string>
using namespace std;
int main(){
	int t, n, p;
	cin >> t;
	string comandos[100];
	for (int i = 0; i<t; i++){
		p = 0;
		cin >> n;
		getline(cin,comandos[0]);
		for (int j = 0; j<n; j++){
			getline(cin,comandos[j]);
		loop:
			if (comandos[j].compare("LEFT")==0){
				p--;
			}
			else if (comandos[j].compare("RIGHT")==0){
				p++;
			}
			else{
				comandos[j] = comandos[stoi(comandos[j].erase(0, 8)) - 1];
				goto loop;
			}

		}
		cout << p << endl;
	}
	return 0;
}