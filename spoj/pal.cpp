/*---------------HELPERS--------------*/

#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debug(x,y) cerr << #x << ": " << x << "\t" << #y << ": " << y << endl

#define MAX 2000

using namespace std;

template<typename T>
std::ostream& print(std::ostream &out, T const &val) { return (out << val << " "); }

template<typename T1, typename T2>
std::ostream& print(std::ostream &out, std::pair<T1, T2> const &val) { return (out << "{" << val.first << " " << val.second << "} "); }

template<template<typename, typename...> class TT, typename... Args>
std::ostream& operator<<(std::ostream &out, TT<Args...> const &cont) {
  for(auto elem : cont) print(out, elem);
  return out;
}

typedef  pair<int,int> pii;
typedef  pair<pii,int> ppi;
typedef vector<int> vi;
typedef vector<pii> vii;

/*---------------HELPERS--------------*/

int pal(char *a,char *b){
	if(a==b){
		return 1;
	} else{
		if (*a==*b){
			return pal(a+1,b-1);
		}else{
			return 0;
		}
	}
}

int min_size(vi graph[MAX],int start,int end,int initial){
	int min = MAX;
	for(int node : graph[start]){
		if(node==end)
			return initial;
		int new_min = min_size(graph,node+1,end,initial+1);
		if(new_min<min)
			min = new_min;
	}
	debug(min);
	return min;
}

int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n) break;

		char str[MAX];
		scanf("%s",str);

		vi graph[MAX];
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if(pal(str+i,str+j)){
					graph[i].push_back(j);
					debug(i);
					debug(j);
				}
			}
		}

		vi starts;
		int fnal= min_size(graph,0,n-1,0);
		debug(fnal);
	}
	return 0;
}
