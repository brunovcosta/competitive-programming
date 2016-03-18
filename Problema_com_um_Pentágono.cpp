#include<stdio.h>
#include<cmath>
#define PI 3.141592653589793L
int main(){
	double a;
	while (scanf("%lf", &a) != EOF)
		printf("%.10lf\n", sin(108 * PI / 180) / sin(63 * PI / 180) *a);
	return 0;
}
