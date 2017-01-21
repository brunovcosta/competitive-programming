#include<cstdio>
#include<stack>
#include<vector>
#include<map>
#define max(a,b) (a>b?a:b)
using namespace std;
int finalize(int a,int b){
	if(a==b)
		return a+1;
	else
		return max(a,b);
}
#include "../lib/grafo.cpp"
int main(){
	for(;;){
		int n1,n2,d;
		scanf("%d%d%d",&n1,&n2,&d);
		Grafo grafo(n1+n2);
		if(n1==0 && n2==0 & d==0)
			break;
		for(int i=0;i<d;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			grafo.apontar(a-1,b-1);
		}
		stack<int> ordenado = grafo.topoSort();
		vector<pair<int,int> > order;
		/* após fazer a ordenação topológica, eu preciso criar uma lista de correlação
		 * onde ela tenha essa mesma ordenação topológica.
		 */
		while(!ordenado.empty()){
			for(int t=0;t<grafo.adj[ordenado.top()].size();t++){
				order.push_back(pair<int,int>(ordenado.top(),grafo.adj[ordenado.top()][t]));
			}
			ordenado.pop();
		}

		int maxLeft=0;
		int maxRight=0;
		int counter[100000]={};
		for(int i=0;i<d;i++){
			int a=order[i].first;
			int b=order[i].second;
			bool left = b>=n1&&a<n1;
			bool right = a>=n1&&b<n1;
			if(left || right)
				counter[a]=max(counter[a],1+counter[b]);

			if(counter[a]>maxLeft && a<n1){
				maxLeft=counter[a];
			}
			if(counter[a]>maxRight && a>=n1){
				maxRight=counter[a];
			}
		}
		printf("%d\n",2+finalize(maxLeft,maxRight));
	}
	return 0;
}
