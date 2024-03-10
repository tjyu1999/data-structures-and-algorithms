# include <iostream>
# include <queue>

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

    virtual void bfs(int v){
        visited = new bool [num_vertex];
        fill(visited, visited + num_vertex, false);
        visited[v] = true;
        queue<int> q;
        q.push(v);
        
        while(!q.empty()){
            v = q.front();
            q.pop();
            
            for(){
                if(!visited[n]){
                    q.push(n);
                    visited[n] = true;
                }
            }
        }
        
        delete [] visted;
    }
};
