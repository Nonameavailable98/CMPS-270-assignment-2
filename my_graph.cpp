
#include <map>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class Graph {
 protected :
 map <int , vector <int > > outgoing ;

public :
 Graph ( const vector <int > & startPoints , const vector <int > &
endPoints );
int numOutgoing ( const int nodeID ) const ;
 const vector <int > & adjacent ( const int nodeID ) const ;
//requires
//nothing
//effects:
//adds edge to the graph
  void addEdge(int v, int w){
    outgoing.at(v).push_back(w);
 }

 //Helper Function
 bool isCyclicUtil(int v, bool visited[], bool *rs){
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        rs[v] = true;

        
        vector<int>::iterator i;
        for (i = outgoing.at(v).begin(); i != outgoing.at(v).end(); ++i){
            if ( !visited[*i] && isCyclicUtil(*i, visited, rs) )
                return true;
            else if (rs[*i])
                return true;
        }
 
    }
    rs[v] = false;  // remove the vertex from recursion stack
    return false;
 }

 //requires
 //nothing
 //effects:
 //returns true if the graph has a non-trivial cycle and false otherwise
  bool isCyclic(){
    // Mark all the vertices as not visited and not part of recursion
    // stack
    int V = outgoing.size();
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
 }

};
//requires:
//nothing 
//effects:
//creates a new graph object
Graph :: Graph ( const vector <int > & startPoints , const vector <int > &
endPoints ) {
 if( startPoints.size() != endPoints.size()){
    throw invalid_argument (" Start /end point lists differ in length ");
 }

for( unsigned i = 0; i < startPoints . size (); i++ ) {
 int start = startPoints [i], end = endPoints [i];
 outgoing [ start ].push_back(end);
 outgoing [end ]; // Just to indicate this node exists
}
}
//requires:
//nothing
//effects:
//Returns the number of outgoing edges from nodeID
 int Graph :: numOutgoing ( const int nodeID ) const {
 return adjacent ( nodeID ). size ();
}
//requires:
//nothing
//effects:
//Returns a reference to the list of nodes to which nodeID has outgoing edges
 const vector <int > & Graph :: adjacent ( const int nodeID ) const {
 map <int , vector <int > >:: const_iterator i = outgoing . find ( nodeID );
 if(i == outgoing . end ()) {
 throw invalid_argument (" Invalid node ID");
}
 return i-> second ;
 };
int main() 
{
    vector<int> s;
    s.push_back(0);
    s.push_back(0);
    s.push_back(0);
    s.push_back(4);
    s.push_back(4);
    s.push_back(3);

    vector<int> e;
    e.push_back(1);
    e.push_back(2);
    e.push_back(3);
    e.push_back(3);
    e.push_back(1);
    e.push_back(1);

    

    Graph g(s,e) ;
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    cout << g.isCyclic() << endl;
    cout << g.numOutgoing(1) << endl;

    vector<int> start;
    start.push_back(0);
    start.push_back(0);
    start.push_back(0);
    start.push_back(4);
    start.push_back(4);
    start.push_back(3);
    vector<int> end;
    end.push_back(1);
    end.push_back(2);
    end.push_back(3);
    end.push_back(3);
    end.push_back(1);
    end.push_back(1);
    

    Graph g1(start,end);
    int size = g1.numOutgoing(0);
    cout<<"the number of outgoing nodes from nodeID 0 is : "<<size<<endl;
 


    int size2 = g1.numOutgoing(123);
        cout<<"the number of outgoing nodes from nodeID 123 is : "<<size<<endl;

    return 0;
}