#include<stdio.h>
#include<limits.h>

int V,E;
int parent[100];
int cost[100][100];

int find(int i) {
	while(parent[i]!=i)
		i=parent[i];
	return i;
}

int union1(int i, int j) {
	int a= find(i);
	int b= find(j);
	parent[a]=b;
}

void krushkal() {
	int mincost=0;
	int edge_count=0;
	while(edge_count<V-1) {
		int min=INT_MAX, a=-1, b=-1;
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				if(find(i)!=find(j) && cost[i][j]<min) {
					min=cost[i][j];
					a=i;
					b=j;
				}
			}
		}

		union1(a,b);
		mincost+=min;
		edge_count++;

		printf("\nEdge %d : %d,%d Min: %d",edge_count,a,b,min);
	}
	printf("\nMinCost: %d",mincost);
}

int main() {
	printf("Enter no. of Vertices and Edges: ");
	scanf("%d %d",&V,&E);

	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			cost[i][j]=INT_MAX;
		}
	}

	for(int i=0; i<E; i++) {
		int m,n;
		printf("Enter Edge and Cost: ");
		scanf("%d %d",&m,&n);
		printf("Enter Cost of edge %d,%d",m,n);
		scanf("%d",&cost[m][n]);
		cost[n][m]=cost[m][n];
	}

	for(int i=0; i<V; i++) {
		parent[i]=i;
	}
	krushkal();
	return 0;
}

