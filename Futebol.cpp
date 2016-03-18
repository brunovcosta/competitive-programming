#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100000
using namespace std;
int compare(const void *a,const void *b){
	return (*(int*)a - *(int*)b);
}
int main(){
	int n, g, s[MAX], r[MAX],p;
	vector<int> delta;
	while (true){
		cin >> n;
		if (cin.eof())
			break;
		cin >> g;

		p = 0;
		delta.erase(delta.begin(), delta.end());
		for (int t = 0; t < n; t++){
			cin >> s[t] >> r[t];
			if (r[t] >= s[t])
				delta.push_back(r[t] - s[t]);
			else
				p+=3;
		}
		qsort(&delta[0],delta.size(),sizeof(int),compare);
		for (int t = 0; t < (unsigned int)delta.size(); t++){
			if (g>=delta[t]+1){
				g -= delta[t]+1;
				p += 3;
			}
			else if (g==delta[t]){
				p ++;
				g -= delta[t];
			}
			if (g<delta[t]){
				break;
			}

		}
		cout << p << endl;
	}
	return 0;
}