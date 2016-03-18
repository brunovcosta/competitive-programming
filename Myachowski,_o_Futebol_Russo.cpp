#include<cstdio>
#include<cmath>
int main(){
	double x0, y0, dx, dy, a, b, t, alfa, beta, gama, x1, y1, x2, y2,x4,y4,x3,y3;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &dx, &dy, &a, &b)!=EOF){
		alfa = dx *dx / (a*a) + dy*dy / (b*b);
		beta = (2 * x0*dx) / (a*a) + (2 * y0*dy) / (b*b);
		gama = (x0 / a)*(x0 / a) + (y0 / b)*(y0 / b) - 1;
		t = (-beta + sqrt(beta*beta - 4 * alfa*gama)) / (2 * alfa);
		x1 = x0 + t*dx;
		y1 = y0 + t*dy;
		printf("%.3lf %.3lf\n", x1, y1);
		t = (b*b*x1*(x0 - x1) + a*a*y1*(y0 - y1)) / (a*a*a*a*y1*y1 + b*b*b*b*x1*x1);
		x4 = x1 + t*b*b*x1;
		y4 = y1 + t*a*a*y1;
		x3 = 2 * x4 - x0;
		y3 = 2 * y4 - y0;
		alfa = (x3 - x1)*(x3 - x1) / (a*a) + (y3 - y1)*(y3 - y1) / (b*b);
		beta = 2 * x1*(x3 - x1) / (a*a) + 2 * y1*(y3 - y1) / (b*b);
		gama = (x1 / a)*(x1 / a) + (y1 / b)*(y1 / b) - 1;
		t = (-beta + sqrt(beta*beta - 4 * alfa*gama)) / (2 * alfa);
		x2 = t*x3 + (1 - t)*x1;
		y2 = t*y3 + (1 - t)*y1;
		printf("%.3lf %.3lf\n", x2, y2);
	}
}