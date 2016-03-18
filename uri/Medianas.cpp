#include<cstdio>
#include<cmath>
int main(){
	double m1, m2, m3;
	while (scanf("%lf%lf%lf", &m1, &m2, &m3) != EOF){
		m1 = std::abs(m1);
		m2 = std::abs(m2);
		m3 = std::abs(m3);
		double sm = (m1 + m2 + m3) / 2;
		if (m1 >= m2 + m3 || m2 >= m1 + m3 || m3 >= m1 + m2){
			printf("-1.000\n");
			continue;
		}
		printf("%.3lf\n", 4 * sqrt(sm*(sm - m1)*(sm - m2)*(sm - m3)) / 3);
	}
	return 0;
}