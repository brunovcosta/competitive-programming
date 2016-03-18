#include<cstdio>
#define MAX 1000000
int n,m,p[MAX],root[MAX],score[MAX],rank[MAX],cont;
int min(int a,int b){
	return a<b?a:b;
}
int find(int a){
	if(root[a]==a)
		return a;	
	else
		return root[a]=find(root[a]);
}
int main(){
	while(1){
		cont=0;
		scanf("%d%d",&n,&m);
		if(n*n+m*m==0)
			break;
		for(int ime=0;ime<n;ime++){
			scanf("%d",p+ime);
			root[ime]=ime;
			score[ime]=p[ime];
			rank[ime]=0;
		}
		for(int ime=0;ime<m;ime++){
			int q,a,b;
			scanf("%d%d%d",&q,&a,&b);
			a--;b--;
			if(q==1){//união
				int aRoot=find(a);
				int bRoot=find(b);
				if(aRoot!=bRoot){
					if(rank[aRoot]<rank[bRoot]){
						root[aRoot]=bRoot;
						score[bRoot]+=score[aRoot];
					}else if(rank[bRoot]<rank[aRoot]){
						root[bRoot]=aRoot;
						score[aRoot]+=score[bRoot];
					}else{
						root[bRoot]=aRoot;
						score[aRoot]+=score[bRoot];
						rank[aRoot]++;
					}
					
				}
			}else{//batalha
				int sca=score[find(a)];
				int scb=score[find(b)];
				int r=find(0);
				if (root[a]==r&&sca>scb)
					cont++;
				if (root[b]==r&&scb>sca)
					cont++;
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}