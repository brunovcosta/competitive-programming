#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAX 99999
using namespace std;
class Point{
	public:
		int x;
		int y;
		Point();
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
int bsearch(Point bomb,Point point,int heights[],int heightsSize,int min,int max){
	int mid=(min+max)/2;
	Point deltaPoint = Point(
		point.x-bomb.x,
		point.y-bomb.y
	);
	Point deltaHeightMin = Point(
		-bomb.x,
		heights[min]-bomb.y
	);
	Point deltaHeight = Point(
		-bomb.x,
		heights[mid]-bomb.y
	);
	Point deltaHeightMax = Point(
		-bomb.x,
		heights[max]-bomb.y
	);
	double divPoint = ((double)deltaPoint.y)/deltaPoint.x;
	double divHeightMin =((double)deltaHeightMin.y)/deltaHeightMin.x;
	double divHeight =((double)deltaHeight.y)/deltaHeight.x;
	double divHeightMax =((double)deltaHeightMax.y)/deltaHeightMax.x;

	//cout<<"-----------------------\n";
	//cout<<"divPoint:"<<divPoint<<"\n";
	//cout<<"divHeightMin:"<<divHeightMin<<"\n";
	//cout<<"divHeight:"<<divHeight<<"\n";
	//cout<<"divHeightMax:"<<divHeightMax<<"\n";
	//cout<<"min:"<<min<<"\n";
	//cout<<"mid:"<<mid<<"\n";
	//cout<<"max:"<<max<<"\n";
	//cout<<"-----------------------\n";
	if(divPoint<=divHeightMin)
		return 0;
	if(divPoint>=divHeightMax)
		return max+1;
	if(divPoint==divHeight)
		return mid%2==0?mid:mid+1;
	if(min==mid)
		return max;
	if(divPoint>divHeight)
		return bsearch(bomb,point,heights,heightsSize,mid,max);
	if(divPoint<divHeight)
		return bsearch(bomb,point,heights,heightsSize,min,mid);
}
bool safe(Point bomb,Point point,int heights[], int heightsSize){
	int search =  bsearch(bomb,point,heights,heightsSize,0,heightsSize-1);
	//cout<<"-----------------------\n";
	//cout<<"search:\n";
	//cout<<search<<endl;
	//cout<<"-----------------------\n";
	return search%2==1;
}
int main(){
	int heights[MAX];
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++){
		Point bomb = Point();
		scanf("%d%d",&(bomb.x),&(bomb.y));

		int p;
		scanf("%d",&p);
		int j;
		for(j=0;j<2*p;j+=2){
			scanf("%d",heights+j);
			scanf("%d",heights+j+1);
		}
		sort(heights,heights+2*p);

		int g;
		scanf("%d",&g);
		int count=0;
		int k;
		for(k=0;k<g;k++){
			Point point = Point();
			scanf("%d%d",&(point.x),&(point.y));
			if(safe(bomb,point,heights,2*p))
				count++;
		}
		printf("%d\n",count);
	}

	return 0;
}
