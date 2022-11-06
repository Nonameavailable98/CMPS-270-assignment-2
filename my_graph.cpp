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
int main() 
{
    return 0;
}