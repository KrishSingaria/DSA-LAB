#include <iostream>
#include <vector>

using namespace std;

class Graph{
private:
	int V;
	vector<vector<int>> adjMatrix;
	vector<vector<int>> adjList;
public:
	Graph(int vertices){
		V = vertices;
		adjMatrix.resize(V,vector<int>(V,0));
		adjList.resize(V);
	}
	void addEdge(int src,int dest,bool isDirected = true){
		adjMatrix[src][dest] = 1;
		adjList[src].push_back(dest);
		if(!isDirected){
			adjMarix[dest][src] = 1;
			adjList[dest].push_back(src);
		}
	}
	void printAdjancyMatrix(){
		cout<<" Adjacency Matrix: "<<endl;
		for (int i = 0; i < V; i += 1)
		{
			for (int j = 0; j < V; j += 1)
			{
				cout<< adjMarix[i][j] <<" ";
			}
			cout<<endl;
		}
	}
	void printAdjancyList(){
		cout<<" Adjacency List: "<<endl;
		for (int i = 0; i < V; i += 1)
		{
			cout << i << "-->";
			for(int j : adjList[i]){
				cout << j << " ";
			}
			cout<<endl;
		}
	}
	void computeDegrees(){
		vector<int>
	}
};
