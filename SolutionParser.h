#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Interval.h"

class SolutionParser{
private:
    /* data */
public:
    SolutionParser();
    ~SolutionParser();

    void writeCSV(vector<Interval *> solution);
};


