#include<stdio.h>
int main(){
	double a;
	while (scanf("%lf", &a) != EOF)
		printf("%.3lf %.3lf %.3lf\n", .31514674362772023*a*a, .51129916633435180*a*a, .17355409003792754*a*a);
	return 0;
}