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
			adjMatrix[dest][src] = 1;
			adjList[dest].push_back(src);
		}
	}
	void printAdjancyMatrix(){
		cout<<" Adjacency Matrix: "<<endl;
		for (int i = 0; i < V; i += 1)
		{
			for (int j = 0; j < V; j += 1)
			{
				cout<< adjMatrix[i][j] <<" ";
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
	void computeDegrees()
	{
		vector<int> iN(V,0);
		vector<int> ouT(V,0);
		for(int i=0;i<V;i++)
		{
			ouT[i] = adjList[i].size();
			for(int j=0;j<adjList[i].size();j++)
				iN[adjList[i][j]]++;
		}
	
		cout << "Vertex\t\tIn\t\tOut" << endl;
		for(int k = 0; k < V; k++)
		{
			cout << k << "\t\t"
				<< iN[k] << "\t\t"
				<< ouT[k] << endl;
		}
	}
};
int main() {
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1,false);
    g.addEdge(0, 2,false);
	g.addEdge(1, 2,false);
    g.addEdge(1, 3,false);
    g.addEdge(2, 4,false);

    g.printAdjancyMatrix();
    g.printAdjancyList();
    g.computeDegrees();

    return 0;
}
