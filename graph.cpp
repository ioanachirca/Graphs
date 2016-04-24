#include <vector>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <stack>
#include <algorithm>
#include <queue>
#include "graph.h"

bool compareByNNodeIdex(const NodeInfo &a, const NodeInfo &b)
{
	return a.nNodeIndex < b.nNodeIndex;
}

NodeInfo::NodeInfo()
{
	color=WHITE;
	dist=INT_MAX;
	tDesc=0;
	tFin=0;
	nNodeIndex=-1;
}

std::ostream& operator<<(std::ostream& out,Node& node)
{
	for (std::vector<int>::iterator it=node.neigh.begin();it!=node.neigh.end();it++)
		out<<*it<<" ";

	//secventa poate fi rescrisa:
	/*
	std::ostream_iterator<int> out_it(out," ");
	std::copy(node.neigh.begin(),node.neigh.end(),out_it);
	*/


	out<<std::endl;
	return out;

}


Graph::Graph(int n)
{
	this->n=n;
	nodes=new Node[n];
}


Graph::~Graph()
{
	delete [] nodes;
}

void Graph::addEdge(int u,int v,EDGE_DIRECTION dir)
{
	//TODO1
	//std::cout<<"here...";
	if (u < n && u >= 0 && v < n  && v >= 0)
	{
		//std::cout<<"in condition";
		if (std::find(nodes[u].neigh.begin(), nodes[u].neigh.end(), v) == nodes[u].neigh.end())
		{
			nodes[u].neigh.push_back(v);
			//std::cout<< "in add edge";
		}

		if (dir == BIDIRECTIONAL && std::find(nodes[v].neigh.begin(), nodes[v].neigh.end(), u) == nodes[v].neigh.end())
		{
			nodes[v].neigh.push_back(u);
		}
	}
}


void Graph::bfs(int node)
{
	std::vector<NodeInfo> nodeInfos(n);
	std::queue<int> Q;

	std::cout<<"BFS Traversing from node "<<node<<std::endl;


	//TODO2
	nodeInfos[node].color = GRAY;
	nodeInfos[node].dist = 0;
	Q.push(node);

	while (!Q.empty())
	{
		int neighbour = Q.front();
		std::cout << neighbour << " ";
		Q.pop();
		for (std::vector<int>::iterator it = nodes[neighbour].neigh.begin(); it != nodes[neighbour].neigh.end(); it++)
		{
			if (nodeInfos[*it].color == WHITE)
			{
				nodeInfos[*it].color = GRAY;
				nodeInfos[*it].nNodeIndex = neighbour;
				nodeInfos[*it].dist = nodeInfos[neighbour].dist + 1;
				Q.push(*it);
			}

			nodeInfos[neighbour].color = BLACK;
		}
	}

	std::cout<<std::endl;
	//std::sort(nodeInfos.begin(), nodeInfos.end(), compareByNNodeIdex);

}

void dfsVisit(std::vector<NodeInfo> &nodeInfos, int index, int time_count)
{
	nodeInfos[index].tDesc = time_count;
	nodeInfos[index].color = GRAY;
	std::cout << index << " ";
}

void Graph::dfs(int node)
{
	std::vector<NodeInfo> nodeInfos(n);
	std::stack<int> S;
	int time_count = 0;

	std::cout<<"DFS Traversing from node "<<node<<std::endl;
	//TODO2
	dfsVisit(nodeInfos, node, time_count);
	S.push(node);

	while (!S.empty())
	{
		int topNode = S.top();
		int neighbour = -1;

		for (std::vector<int>::iterator it = nodes[topNode].neigh.begin(); neighbour == -1 && it != nodes[topNode].neigh.end(); it++)
		{
			if (nodeInfos[*it].color == WHITE)
			{
				neighbour = *it;
			}
		}

		if (neighbour != -1)
		{
			nodeInfos[neighbour].nNodeIndex = topNode;
			time_count++;
			dfsVisit(nodeInfos, neighbour, time_count);
			S.push(neighbour);
		}
		else
		{
			time_count++;
			nodeInfos[topNode].tFin = time_count;
			nodeInfos[topNode].color = BLACK;
			S.pop();
		}
	}

	std::cout<<std::endl;
}

void Graph::sortNeigh()
{
	for (int i=0;i<n;i++)
	   std::sort(nodes[i].neigh.begin(),nodes[i].neigh.end());
}


void Graph::printPretty()
{
	std::cout<<"Print graph:"<<std::endl;
	for (int i=0;i<n;i++)
		std::cout<<i<<"->"<<nodes[i];
}
