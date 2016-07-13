//Coded by Hechen Hu in July 12,2016
//The Code of Map Data
#include <map>
using std::map ;


struct PATH
{
	char PathName [] ; 
	NODEPOINT *NodeOne ;//Point At The First Node Connected With This Side
	NODEPOINT *NodeTwo ;//Point At The Next Node Connected With This Side
	int Cost ; 
};
struct NODEPOINT
{
	char* NodeName ;
	int BranchNum ;
	int weight ;
	Location WhereIsThisPoint ; 
	int NodeType ;
};
struct COORDINATE
{
	int x,y，z;
	&COORDINATE operator == (&COORDINATE A,&COORDINATE B)
	{
		if(A.x == B.x && A.y == B.y && A.z == B.z)
			return true ;
	}
};
struct MAP
{
    map<int,WayPoint > Point;
    map<int,Path> Side;
};
struct ROUTEPOINT
{
    WAYPOINT Node ;
    WAYPOINT *Next ;
};
class MapManager
{
    private:
            MAP MapData ;
            COORDINATE CurrLocation ;
    public:
           ROUTEPOINT FindRoute(char Algorithm[],NODEPOINT Destination)//Find Route According to The Sum Of Node And Choose The Algorithm
           	{
           		  static COORDINATE Direction ;
                  while(CurrLocation != Destination)
                  if(CurrLocation.z == Destination.z)
                  {
                        
                  }
                  else if(CurrLocation.z != Destination.z)
                  {

                  }
           	}      
            

};