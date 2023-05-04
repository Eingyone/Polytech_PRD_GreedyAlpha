#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Interval{
private:
	short id; /** < Id of the inverval*/
	long long startDate; /** < Start date (in seconds) of the interval*/
	long long stopDate; /** < Stop date (in seconds) of the interval*/
	string channel; /** < Channel code of the interval */
	string hashcode; /** < Hashcode of the interval (created using the name of the programm)*/
	short weight; /** < Weight of the interval (generated randomly using the hashcode)*/

public :
	Interval();
	Interval(short id, long long startDate, long long stopDate, string channel, string hashcode);

	short getId();
	long long getStartDate();
	long long getStopDate();
	string getChannel();
	string getHashcode();
	short getWeight();
	void setStartDate(long long startDate);
	void setStopDate(long long stopDate);

	void generateRandomWeight();
	void printInterval();

};

