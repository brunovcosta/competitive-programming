#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int orient(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	return b.first*c.second - b.second*c.first - (a.first*c.second - a.second*c.first) + a.first*b.second - a.second*b.first;
}

set<pair<int, int> > cHull(set<pair<int, int> > in){
	if (in.size() <= 2){
		return in;
	}
	set<pair<int, int> > top, down;
	top.insert(*in.begin());
	top.insert(*(++in.begin()));
	down.insert(*in.begin());
	down.insert(*(++in.begin()));

	for (set<pair<int, int> >::iterator it = ++++in.begin(); it != in.end(); it++){
		while (top.size() >= 2 && orient(*it, *(--top.end()), *(----top.end())) < 0)
			top.erase(*(--top.end()));
		top.insert(*it);
	}

	for (set<pair<int, int> >::iterator it = ++++in.begin(); it != in.end(); it++){
		while (down.size() >= 2 && orient(*it, *(--down.end()), *(----down.end())) > 0)
			down.erase(*(--down.end()));
		down.insert(*it);
	}
	for (set<pair<int, int> >::iterator it = down.begin(); it != down.end(); it++)
		top.insert(*it);
	return top;
}
int main(){
	int n, camadas;
	set<pair<int, int> > pontos, borda;
	while (true){
		camadas = 0;
		pontos.erase(pontos.begin(), pontos.end());
		borda.erase(borda.begin(),borda.end());
		cin >> n;
		if (!n)
			break;
		for (int t = 0; t < n; t++){
			pair<int, int> temp;
			cin >> temp.first >> temp.second;
			pontos.insert(temp);
		}
		while (pontos.size() >0)
		{
			borda = set<pair<int, int> >(cHull(pontos));
			camadas++;
			for (set<pair<int, int> >::iterator it = borda.begin(); it != borda.end(); it++)
				pontos.erase(*it);
		}
		if (camadas % 2 == 0){
			cout << "Do not take this onion to the lab!" << endl;
		}
		else{
			cout << "Take this onion to the lab!" << endl;
		}

	}
	return 0;
}