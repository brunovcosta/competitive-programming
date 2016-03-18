#include<cstdio>
#include<cstring>
#include<cmath>
int main(){
	char palavra[1000];
	int l, c, n, i, j;
	while (scanf("%d%d%d", &n, &l, &c) !=EOF){
		i = 1; j = 0;
		for (int t = 1; t <= n; t++){
			scanf("%s", palavra);
			j += strlen(palavra);
			if (j != c&&t != n)
				j++;
			if (j > c){
				i++;
				j = strlen(palavra);
				if (j != c&&t != n)
					j++;
			}

		}
		int paginas = (i / l) + ((i%l == 0) ? 0 : 1);
		printf("%d\n", paginas);
	}
	return 0;
}