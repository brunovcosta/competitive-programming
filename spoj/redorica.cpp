#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int main(){
	for(int test = 1 ;;test++){
		int m,n;
		scanf("%d%d",&n,&m);
		if(!n)
			break;

		vector<pair<int,int> > graph[1000];
		bool visited[1000] = {false};

		for(int t=0;t<m;t++){
			unsigned int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			graph[x-1].push_back(make_pair(y-1,z));
			graph[y-1].push_back(make_pair(x-1,z));
		}

		printf("Teste %d\n",test);

		vector<int> tree;
		tree.push_back(0);
		for(int t=1;t<n;t++){
			int smaller_z = 101;
			int closest_neighbor = -1;
			int closest_node = -1;
			for(auto node : tree){
				for(auto neighbor : graph[node]){
					if(!visited[neighbor.first] && neighbor.second < smaller_z){
						smaller_z = neighbor.second;
						closest_neighbor = neighbor.first;
						closest_node = node;
					}
				}
			}
			tree.push_back(closest_neighbor);
			visited[closest_neighbor] = true;
			visited[closest_node] = true;
			
			int x= closest_node+1;
			int y = closest_neighbor+1;
			printf("%d %d\n",min(x,y),max(x,y));
		}
		puts("");
	
	}

	return 0;
}
