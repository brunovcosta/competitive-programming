#include<cstdio>
#include<cassert>
class vec2{
	public:
		double x,y;
		vec2();
		vec2(double x,double y);
		vec2 plus(vec2 other);
		vec2 minus(vec2 other);
};
vec2::vec2(){
	this->x=0;
	this->y=0;
}
vec2::vec2(double x,double y){
	this->x=x;
	this->y=y;
}
vec2 vec2::plus(vec2 other){
	return vec2(this->x+other.x,this->y+other.y);
}
vec2 vec2::minus(vec2 other){
	return vec2(this->x-other.x,this->y-other.y);
}

class segment{
	public:
		vec2 p1,p2;
		segment();
		segment(vec2 p1,vec2 p2);
};
segment::segment(){
	this->p1=vec2();
	this->p2=vec2();
}
segment::segment(vec2 p1,vec2 p2){
	this->p1=p1;
	this->p2=p2;
}

segment median(segment s){
	vec2 p1=s.p1;
	vec2 p2=s.p2;
	vec2 diff = p2.minus(p1);
	vec2 rotated_diff = vec2(diff.y,-diff.x);

	vec2 middle = vec2((p1.x+p2.x)/2,(p1.y+p2.y)/2);

	return segment(middle,middle.plus(rotated_diff));
}
double detProd(double a,double b,double c, double d){
	return a*d-b*c;
}
vec2 intersection(segment s1,segment s2){
	/* compute intersection solving linnear system of equations
	 * |dx1   -dx2||t| - |dx|
	 * |dy1   -dy2||w| - |dy|
	 */

	double x1=s1.p1.x;
	double x2=s1.p2.x;
	double x3=s2.p1.x;
	double x4=s2.p2.x;

	double y1=s1.p1.y;
	double y2=s1.p2.y;
	double y3=s2.p1.y;
	double y4=s2.p2.y;

	double x1y1x2y2 = detProd(x1,y1,x2,y2);
	double x3y3x4y4 = detProd(x3,y3,x4,y4);
	
	double x11x21 = detProd(x1,1,x2,1);
	double x31x41 = detProd(x3,1,x4,1);

	double y11y21 = detProd(y1,1,y2,1);
	double y31y41 = detProd(y3,1,y4,1);

	double detxup = detProd(x1y1x2y2,x11x21,x3y3x4y4,x31x41);
	double detyup = detProd(x1y1x2y2,y11y21,x3y3x4y4,y31y41);
	double detdown = detProd(x11x21,y11y21,x31x41,y31y41);
	

	return vec2(detxup/detdown,detyup/detdown);
}
vec2 center(segment s1,segment s2){
	segment m1 = median(s1);
	segment m2 = median(s2);
	return intersection(m1,m2);
}
void test(){
	vec2 i1=vec2(1,0);
	vec2 i2=vec2(2,0);

	vec2 j1=vec2(0,1);
	vec2 j2=vec2(0,2);

	segment si = segment(i1,i2);
	segment sj = segment(j1,j2);

	assert(intersection(si,sj).x==0);
	assert(intersection(si,sj).y==0);

	assert(median(si).p1.x==1.5);
	assert(median(sj).p1.y==1.5);

	assert(center(si,sj).x==1.5);
	assert(center(si,sj).y==1.5);
}
int main(){
	test();
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++){
		segment s1,s2;
		scanf("%lf %lf",&(s1.p1.x),&(s1.p1.y));
		scanf("%lf %lf",&(s2.p1.x),&(s2.p1.y));
		scanf("%lf %lf",&(s1.p2.x),&(s1.p2.y));
		scanf("%lf %lf",&(s2.p2.x),&(s2.p2.y));

		printf("Caso #%d: %.2lf %.2lf\n",i+1,center(s1,s2).x,center(s1,s2).y);
	}
	return 0;
}
