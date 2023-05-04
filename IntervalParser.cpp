#include "IntervalParser.h"

/****************************************************************************
 * Constructors / Destructors
 ****************************************************************************/

/**
 * @brief Construct a new Interval Parser:: Interval Parser object
 * 
 */
IntervalParser::IntervalParser(/* args */){
}

/**
 * @brief Destroy the Interval Parser:: Interval Parser object
 * 
 */
IntervalParser::~IntervalParser(){
}

/****************************************************************************
 * Methods
 ****************************************************************************/

/**
 * @brief Parses the file and returns a vector of intervals
 * 
 * @param fileName The PATH of the file to parse
 * @return vector<Interval> 
 */
vector<Interval> IntervalParser::parse(string fileName){
    // We open the file
    fstream CSVfile(fileName);
    vector<Interval> intervalList;

    //We make sure the file is open
    if(!CSVfile.is_open()) throw runtime_error("Could not open file");

    // Helper vars
    string line, cell;

    // Check if the file is open
    if(CSVfile.good()){
        int interval_count = 0;
        // We iterate through each line of the file (header is ignored)
        while(getline(CSVfile, line)){
            // Initialize the variables we are going to extract
            string channel;
            long long startDate;
            long long stopDate;
            string hashcode;

            // Create a stringstream from line
            stringstream ssLine(line);

            // Get the channel
            getline(ssLine, cell, ',');
            //try{
                channel = cell.c_str();
            //} catch (const std::invalid_argument& ia) {continue;}
            
            // Get the hashcode
            getline(ssLine, cell, ',');
            hashcode = cell.c_str();

            // Get the start date
            getline(ssLine, cell, ',');
            try{
                startDate = stoll(cell);
            } catch (const std::invalid_argument& ia) {continue;}
            
            // Get the stop date
            getline(ssLine, cell, ',');
            try{
                stopDate = stoll(cell);
            } catch (const std::invalid_argument& ia) {continue;}
            

            // We create the interval
            Interval extractedInterval = Interval(interval_count, startDate, stopDate, channel, hashcode);
            // We add the interval to the list
            intervalList.push_back(extractedInterval);
            interval_count++;
        }

    }
    //File close
    CSVfile.close();

    return intervalList;
}

/**
 * @brief Sorts the intervals by start date
 * 
 * @param intervalList The list of intervals to sort
 */
void IntervalParser::sortIntervals(vector<Interval> &intervalList){
    // We sort the list by giving the StartDate as a parameter
    sort (intervalList.begin(), intervalList.end(), [](Interval a, Interval b) {
            return a.getStartDate() < b.getStartDate(); 
    });
}

/**
 * @brief Sets the origin of the start date to 0
 * 
 * @param intervalList The list of intervals to modify
 */
void IntervalParser::originToZero(vector<Interval> &intervalList){
    // We set the origin point of start date to 0
    long long originDifference = intervalList[0].getStartDate();
    for (int i = 0; i < intervalList.size(); i++){
        intervalList[i].setStartDate(intervalList[i].getStartDate() - originDifference);
        intervalList[i].setStopDate(intervalList[i].getStopDate() - originDifference);
    }
}