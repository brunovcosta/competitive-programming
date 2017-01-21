struct Grafo{
	int N;
	vector<int> *adj;
	Grafo(int N){
		this->N=N;
		this->adj = new vector<int>[N];
	}
	void apontar(int a,int b){
		adj[a].push_back(b);
	}
	void recTopo(int v, bool *visitados,stack<int> &pilha){
		visitados[v] = true;

		vector<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); i++)
			if (!visitados[*i])
				recTopo(*i, visitados, pilha);

		pilha.push(v);
	}
	stack<int> topoSort(){
		stack<int> pilha;
		bool *visitados = new bool[N];
		int t;
		for(t=0;t<N;t++)
			visitados[t] = false;
		for(t=0;t<N;t++){
			if(!visitados[t]){
				recTopo(t,visitados,pilha);
			}
		}
		return pilha;
	}
};
