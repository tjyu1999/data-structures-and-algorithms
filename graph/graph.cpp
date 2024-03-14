# include <iostream>
# include <vector>
# include <list>

using namespace std;

class Graph{
private:
    int num_vertex;
    int num_edge;
    vector<list<int>> adjacency;

public:
    Graph():num_vertex(0), num_edge(0){}
    
    ~Graph(){}
    
    int get_num_vertex(){
        return num_vertex;
    }
    
    int get_num_edge(){
        return num_edge;
    }
    
    bool empty(){
        return num_vertex == 0;
    }
    
    int degree(int u){
        return adjacency[u].size();
    }
    
    bool exist_edge(int u, int v){
        for(int n : adjacency[u]){
            if(n == v) return true;
        }
        
        return false;
    }
    
    void insert_vertex(int v){
        if(v >= num_vertex){
            num_vertex++;
            adjacency.resize(num_vertex);
        }
    }
    
    void insert_edge(int u, int v){
        if(!exist_edge(u, v)){
            adjacency[u].push_back(v);
            adjacency[v].push_back(u);
            num_edge++;
        }
    }
    
    void delete_vertex(int v){
        if(v < num_vertex){
            for(auto n : adjacency[v]) adjacency[n].remove(v);
            adjacency[v].clear();
            num_vertex--;
        }
    }
    
    void delete_edge(int u, int v){
        if(exist_edge(u, v)){
            adjacency[u].remove(v);
            adjacency[v].remove(u);
            num_edge--;
        }
    }
    
    void print_graph(){
        for(auto vec : adjacency){
            for(int n : vec) cout << n << " ";
            cout << endl;
        }
    }
};

int main(){
    /*
     *  0---1---3---4
     *    \ | \ |   |
     *      2---5   6---7
     */
    
    Graph graph;
    
    graph.insert_vertex(0);
    graph.insert_vertex(1);
    graph.insert_vertex(2);
    graph.insert_vertex(3);
    graph.insert_vertex(4);
    graph.insert_vertex(5);
    graph.insert_vertex(6);
    graph.insert_vertex(7);
    
    graph.insert_edge(0, 1);
    graph.insert_edge(0, 2);
    graph.insert_edge(1, 2);
    graph.insert_edge(1, 3);
    graph.insert_edge(1, 5);
    graph.insert_edge(2, 5);
    graph.insert_edge(3, 4);
    graph.insert_edge(3, 5);
    graph.insert_edge(4, 6);
    graph.insert_edge(6, 7);
    
    graph.print_graph();
    
    return 0;
}
