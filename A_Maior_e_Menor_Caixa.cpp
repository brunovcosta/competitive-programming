/* Cálculo do volume
 *
 * V = (w-2x)(l-2x)*x
 * V = w*l*x-4*x³-2*(w+l)x²
 *
 * derivando dV/dx = 0 temos:
 * 0 = w*l+12*x²-4*(w+l)*x
 *
 * aplicando baskara, temos:
 * x={[4*(w+l)]+-sqrt(delta)}/24
 * onde:
 * delta = 16*(w+l)² - 4*12*w*l;
 */
#include<cstdio>
#include<cmath>
double min(double a,double b){
	return a<b?a:b;
}
int main(){
	double w,l,maxVol,minVol;
	while(scanf("%lf%lf",&w,&l)!=EOF){
		minVol=min(w,l)/2;
		double delta = 16*(w+l)*(w+l) - 4*12*w*l;
		maxVol = ((4*(w+l))-sqrt(delta))/24;
		printf("%.3lf 0.000 %.3lf\n",maxVol,minVol);
	}
	return 0;
}
