#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#include<vector>
#define p2d pair<double,double>
using namespace std;
double min(double a,double b){
	if (a<b)
		return a;
	else
		return b;
}
double djunta(double minatual,vector<p2d > esq,vector<p2d > dir){
	double min=minatual;
	if(dir[0].first-esq[esq.size()-1].first>min)
		return min;
	for(int i=esq.size()-1;(dir[0].first-esq[i].first<min)&&i>=0;i--){
		for(int j=0;(dir[j].first-esq[i].first<min)&&j<dir.size();j++){
			double dist2=
(esq[i].first-dir[j].first)*(esq[i].first-dir[j].first)+
(esq[i].second-dir[j].second)*(esq[i].second-dir[j].second);
			if(min*min>dist2)
				min=sqrt(dist2);
		}
	}
	return min;
}
double dmin(vector<p2d > pontos){
	if(pontos.size()==1)
		return 100000;
	if(pontos.size()==2)
		return sqrt(
(pontos[0].first -pontos[1].first )*(pontos[0].first -pontos[1].first)+
(pontos[0].second-pontos[1].second)*(pontos[0].second-pontos[1].second));
	size_t const metade=pontos.size()/2;
	vector<p2d > esq(pontos.begin(),pontos.begin()+metade);
	vector<p2d > dir(pontos.begin()+metade,pontos.end());
	double desq=dmin(esq);
	double ddir=dmin(dir);
	return djunta(min(desq,ddir),esq,dir);
}
int main(){
	int n;
	while(scanf("%d",&n)!=0){
		if(n==0)
			break;
		vector<p2d > todos=vector<p2d >();
		for(int t=0;t<n;t++){
			p2d ponto;
			scanf("%lf%lf",&ponto.first,&ponto.second);
			todos.push_back(ponto);
		}
		sort(todos.begin(),todos.end());
		double resp=dmin(todos);
		if(resp<10000)
			printf("%.4lf\n",resp);
		else
			printf("INFINITY\n");
	}
	return 0;
}