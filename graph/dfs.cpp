# include <iostream>

using namespace std;

class Graph{
private:
    int num_vertex;
    int num_edge;

public:
    Graph()
    
    ~Graph(){
        delete [] visited;
    }

    virtual void dfs(){
        visited = new bool [num_vertex];
        fill(visited, visited + num_vertex, false);
        dfs(0);
        delete [] visted;
    }
    
    virtual void dfs(const int v){
        for(){ // find the neighbors of v which named n
            if(visited[n]) dfs[n];
        }
    }
};
