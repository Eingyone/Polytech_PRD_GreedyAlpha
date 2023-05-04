// Greedy.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <chrono>
#include "interval.h"
#include "intervalParser.h"
#include "solutionParser.h"
#include "greedy.h"
#include "Point.h"

using namespace std::chrono;


int main(){
    //MENU
    //We ask the user to input the data file path
    string filename;
    cout << "Input TV data file name: ";
    cin >> filename;

    //We ask the user to input the max number of channels
    int maxChannel;
    cout << "Input max number of channels: ";
    cin >> maxChannel;

    //We ask the user to input the alpha value
    float alpha;
    cout << "Input alpha value: ";
    cin >> alpha;

    //TODO: make a call to the python script to generate the collection.csv file
    //string scriptname = "Python/1_generate_collection.py";
    //string filename = "Data/collection.csv";
    //string command = "python " + scriptname + " " + filename;

    //We start the timer
    auto start = high_resolution_clock::now();

    //We parse the collection file
    IntervalParser parser = IntervalParser();
    vector<Interval> intervals = parser.parse(filename);

    //We sort the intervals by their start time and we set the origin to 0
    parser.sortIntervals(intervals);
    parser.originToZero(intervals);

    //We show the intervals
    cout << "Intervals parsed : " << intervals.size() << endl;
    for (int intervalId = 0; intervalId < intervals.size(); intervalId++) {
        //We generate a random weight for the interval
        intervals[intervalId].generateRandomWeight();
        // [PRINT] //intervals[intervalId].printInterval();
    }

    //We create the greedy object
    Greedy greedy = Greedy(intervals, maxChannel, alpha);

    //We solve the problem
    vector<Interval *> solution = greedy.solve();

    // [PRINT] // cout << "Solution size : " << solution.size() << endl;

    //We print the solution in a csv file
    SolutionParser solutionParser = SolutionParser();
    solutionParser.writeCSV(solution);

    //We stop the timer
    auto stop = high_resolution_clock::now();
    //We calculate the duration in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    //We print the duration
    cout << "Time taken by GREEDY: " << duration.count() << " microseconds" << endl;

}

