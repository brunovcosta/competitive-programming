#include <stdio.h>
int main() {
	int d,vf,vg;
	while(scanf("%d%d%d",&d,&vf,&vg)!=EOF)
		puts(12*12*(vg*vg-vf*vf) < d*d*vf*vf  ? "N" : "S");
	return 0;
}
