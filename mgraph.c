#include <stdio.h>
#include "graph.h"

int main(){
	Graph G;
	//cek createempty dan is empty
	CreateEmptyGraph(&G);
	if(IsEmptyGraph(G)){
		printf("graph empty\n");
	}else{
		printf("graph tidak empty\n");
	}
	return 0;
}