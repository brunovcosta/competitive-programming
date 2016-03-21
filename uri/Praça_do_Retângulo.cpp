#include<cstdio>
#include<algorithm>
#define MAX 10000
using namespace std;
struct Point{
	int x,y;
	Point(void);
	Point(int x,int y);
};
Point::Point(void){
	this->x=0;
	this->y=0;
}
Point::Point(int x,int y){
	this->x=x;
	this->y=y;
}
bool compare(Point p1,Point p2){
	if(p1.x!=p2.x)
		return p1.x<p2.x;
	else
		return p1.y<p2.y;
}
int main(){
	int n;
	scanf("%d",&n);
	Point pontos[MAX];
	int i,j;
	for(i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		pontos[i]=Point(x,y);
	}
	sort(pontos,pontos+n,compare);

	int cont=0;
	for(i=0;i<n;i++){
		int max=999999999,min=-999999999;
		for(j=i+1;j<n;j++){
			if(pontos[j].y>min && pontos[j].y<max){
				cont++;
				if(pontos[i].y<pontos[j].y){
					max=pontos[j].y;
				}else{
					min=pontos[j].y;
				}
			}
		}
	}
	printf("%d",cont);
	return 0;
}
