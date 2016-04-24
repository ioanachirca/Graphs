#include <fstream>
#include <iostream>
#include "graph.h"


using namespace std;


int main()
{
	std::ifstream in("graf.in");
	//std::ifstream in;
	//in.open("graf.in");
	int n,m,nNodeStartBfs,nNodeStartDfs;

	in >> n >> m;
	//cout<<n<<" "<<m<<endl;
	in >> nNodeStartBfs >> nNodeStartDfs;
	//cout<<nNodeStartBfs<<" "<<nNodeStartDfs;

	Graph g(n);
	// citire muchii
	for (int i = 0; i < m; i++)
	{
		int u, v;
		in >> u >> v;
		cout<<u<< " "<<v<<endl;
		g.addEdge(u,v,BIDIRECTIONAL);
	}
	in.close();

	//sortam vecinii nodurilor in ordine crescatoare
	g.sortNeigh();
	g.printPretty();

	// apelare BFS
	g.bfs(nNodeStartBfs);

	// apelare DFS
	g.dfs(nNodeStartBfs);

	return 0;
}
