#include<cstdio>
int max(int a, int b){
	return a > b ? a : b;
}
int min(int a, int b){
	return a < b ? a : b;
}
int main(){
	int l, c, r1, r2,d;
	scanf("%d%d%d%d", &l, &c, &r1, &r2);
	while (l*l + c*c + r1*r1 + r2*r2 != 0){
		bool cabe=true;
		d = (l - r1 - r2)*(l - r1 - r2) + (c - r1 - r2)*(c - r1 - r2);
		cabe =(d>=(r1+r2)*(r1+r2))&&min(l,c)>=2*max(r1,r2);
		printf(cabe?"S\n":"N\n");
		scanf("%d%d%d%d", &l, &c, &r1, &r2);
	}
	return 0;
}