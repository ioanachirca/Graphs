#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>

enum Color
{
  WHITE,
  GRAY,
  BLACK
};

enum EDGE_DIRECTION
{
	BIDIRECTIONAL,
	UNIDIRECTIONAL
};

struct Node {
	std::vector<int> neigh;
};


struct NodeInfo
{
	Color color;
	unsigned int tDesc;
	unsigned int tFin;
	int nNodeIndex;
	unsigned int dist;
	NodeInfo();
};

class Graph
{
private:
	Node* nodes;
	int n;
public:
	Graph(int n);
	~Graph();
	void bfs(int node);
	void dfs(int node);
	void addEdge(int u,int v,EDGE_DIRECTION dir);
	void printPretty();
	void sortNeigh();
};

#endif
