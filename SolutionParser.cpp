#include "SolutionParser.h"

/****************************************************************************
 * Constructors / Destructors
 ****************************************************************************/

SolutionParser::SolutionParser(){
}

SolutionParser::~SolutionParser(){
}

/****************************************************************************
 * Methods
 ****************************************************************************/

/**
 * @brief This method writes the solution in a CSV file
 * 
 * @param solution 
 */
void SolutionParser::writeCSV(vector<Interval *> solution){
    // We open the file
    fstream CSVfile;
    CSVfile.open("Solution/solution.csv", ios::out);
    vector<Interval> intervalList;

    // We make sure the file is open
    if(!CSVfile.is_open()) throw runtime_error("Could not open file");

    // Helper vars
    string line, cell;

    // Check if the file is open
    if(CSVfile.good()){
        // We print the header
        CSVfile << "Channel,Start Date,Stop Date" << endl;
        Interval interval;

        // We iterate through each interval of the solution
        for (int i = 0; i < solution.size(); i++){
            interval = *solution[i];
            // We print the intervals
            CSVfile << interval.getChannel() << "," << interval.getStartDate() << "," << interval.getStopDate() << endl;
        }
    }

    // We close the file
    CSVfile.close();
}