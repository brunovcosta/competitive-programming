#include<bits/stdc++.h>
using namespace std;
bool possible(int a,int b,int c,int d){
	return a<b+c+d&&
		b<a+c+d&&
		c<a+b+d&&
		d<a+b+c;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int t=0;t<n;t++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf(possible(a,b,c,d)?"Possible\n":"Impossible\n");
	}
	return 0;
}
