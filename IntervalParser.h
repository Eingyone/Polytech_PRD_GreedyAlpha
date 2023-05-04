#pragma once

#ifndef IntervalParser_H
#define IntervalParser8H

#include "Interval.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class IntervalParser{
private:
    /* data */
public:
    IntervalParser();
    ~IntervalParser();

    vector<Interval> parse(string fileName);
    void sortIntervals(vector<Interval> &intervalList);
    void originToZero(vector<Interval> &intervalList);
};

#endif
