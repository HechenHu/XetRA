//Coded by Hechen Hu in July 12,2016
//The Code of Map Data
#include <map>
using std::map ;


struct PATH
{
	char PathName [] ; 
	WayPoint *NodeOne ;//Point At The First Node Connected With This Side
	WayPoint *NodeTwo ;//Point At The Next Node Connected With This Side
	int Cost ; 
};
struct WAYPOINT
{
	char* NodeName ;
	int BranchNum ;
	int weight ;
	Location Where ; 
};
struct LOCATION
{
	int x,y，z;
};
struct MAP
{
    map<int,WayPoint > Point;
    map<int,Path> Side;

};
struct ROUTE
{

};
class MapDataManager
{
    private:
            MAP MapData ;
            LOCATION CurrLocation ;
    public:
            MAP ReadMapData(FILE* FileHandle)
            {

            }        


};