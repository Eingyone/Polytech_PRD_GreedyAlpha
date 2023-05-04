#pragma once

class Point{
private : 
	short id; /** < Id of the point*/
	short cost; /** < Cost of the point (cumulative, used to get a weight)*/
	short minInterval; /** < Minimum weight interval to pass through this point (used to find the list of intervals to find ci)*/

public :
	Point();
	Point(short id);
	short getId();
	short getCost();
	short getMinInterval();
	void setCost(short cost);
	void setMinInterval(short minInterval);
};

