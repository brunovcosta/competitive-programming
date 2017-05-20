#include <cstdio>
#include <vector>
#define MAX 1000

using namespace std;

int dfs_height(vector<int> *graph,int node,bool *ignore){
	int sum=0;
	for(int next : graph[node]){
		if(!ignore[next]){
			sum+=1+dfs_height(graph,next,ignore);
			ignore[next]=true;
		}
		
	}
	return sum;

}

int main(){
	while(1){
		int n;
		vector<int> graph[MAX]={};
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=1;i<=n;i++){
			int t;
			scanf("%d",&t);
			for(int j=0;j<t;j++){
				int b;
				scanf("%d",&b);
				graph[i].push_back(b);
			}
		}

		int max=0;
		int node = -1;
		for(int i=1;i<=n;i++){
			bool ignore[MAX] ={false};
			int deps=dfs_height(graph,i,ignore);
			if(deps > max){
				max = deps;
				node = i;
			}
		}
		printf("%d\n",node);
	}
	return 0;
}
