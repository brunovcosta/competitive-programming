#include <stdio.h>
#define MAX 10000
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
int try(int m,int n,int l,int k,int *count){
	//puts("try");
	if((100*n)%l){
		//puts("(100*n)%l");
		//printf("n: %d\tl: %d\n",n,l);
		return 0;
	}
	int total_divided=0;
	if(count[m]>=n*100/l){
		//printf("m: %d\ttotal_divided: %d\tcount[m]: %d\tn: %d\tl: %d\n",m,total_divided,count[m],n,l);
		//printf("--------------------> %d\n",n*100/l);
		return n*100/l;
	}else{
		for(int t=m-1;t>=m/2;t--){
			//printf("t:%d\tt': %d\n",t,m-t);
			if(t!=m-t){
				int min = min(count[t],count[m-t]);
				count[t]-=min;
				count[m-t]-=min;
				//printf("total_divided+=%d\n",min);
				total_divided+=min;
			}else{
				//printf("total_divided+=%d\n",count[t]/2);
				total_divided+=count[t]/2;
			}
			if(total_divided*l/100>=n)
				break;
		}
		//printf("m: %d\ttotal_divided: %d\tcount[m]: %d\tn: %d\tl: %d\n",m,total_divided,count[m],n,l);
		if(total_divided + count[m]  < n*100/l){
			//puts("total_divided*l/100 + count[m]  < n");
			//puts("impossível");
			return 0;
		}else{
			//printf("--------------------> %d\n",2*total_divided + count[m]);
			return (2*(n*100/l-count[m]) + count[m]);
		}
	}
}

int main(){
	while(1){
		int m,n,l,k,left_count[MAX]={},right_count[MAX]={};
		scanf("%d%d",&m,&n);
		if(m*m+n*n==0)
			break;
		scanf("%d%d",&l,&k);

		for(int i=0;i<k;i++){
			int size;
			scanf("%d",&size);
			left_count[size]++;
			right_count[size]++;
			//printf("%d\t",size);
		}
		//puts("");

		int a = try(m,n,l,k,left_count);
		int b = try(n,m,l,k,right_count);
		if(max(a,b)){
			printf("%d\n",(a*b?min(a,b):max(a,b)));
		}else{
			puts("impossivel");
		}

	}
	return 0;
}
