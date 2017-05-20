#include <stdio.h>
#define MAX 10000
#define min(x,y) (x>y?y:x)
int main(){
	int n,m[MAX];
	char l[MAX];

	while(scanf("%d",&n)!=EOF){
		int count_left[31]={};
		int count_right[31]={};

		for(int t=0;t<n;t++){
			scanf("%d",m+t);
			getchar();
			l[t] = getchar();
			if(l[t]=='E')
				count_left[m[t]-30]++;
			if(l[t]=='D')
				count_right[m[t]-30]++;
		}
		int count=0;
		for(int t=0;t<31;t++){
			count+=min(count_left[t],count_right[t]);
		}
		printf("%d\n",count);
	}

	return 0;
}
