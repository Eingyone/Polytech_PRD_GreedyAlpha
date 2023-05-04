#include "Greedy.h"

/****************************************************************************
 * Constructors / Destructors
 ****************************************************************************/

/**
 * @brief Construct a new Greedy:: Greedy object
 * 
 */
Greedy::Greedy(){
}

/**
 * @brief Construct a new Greedy:: Greedy object
 * 
 * @param omega List of all intervals 
 */
Greedy::Greedy(vector<Interval> omega, short maxChannel, float alpha){
    this->omega = omega;
    this->maxChannel = maxChannel;
    this->alpha = alpha;
}

/****************************************************************************
 * Getters / Setters
 ****************************************************************************/

/**
 * @brief Sets a new list of intervals to find a solution for
 * 
 * @param omega 
 */
void Greedy::setOmega(vector<Interval> omega){
    this->omega = omega;
}

/**
 * @brief Sets a new max channel
 * 
 * @param maxChannel 
 */
void Greedy::setMaxChannel(short maxChannel){
    this->maxChannel = maxChannel;
}

/**
 * @brief Sets a new alpha value
 * 
 * @param alpha 
 */
void Greedy::setAlpha(float alpha){
    this->alpha = alpha;
}

/****************************************************************************
 * Methods
 ****************************************************************************/

vector<Interval *> Greedy::solve(){

    for (int omega_id = 0; omega_id < omega.size(); omega_id++){
        findQi(omega_id);
        findPoints();
        findCi();

        if(exchangeCheck(&omega[omega_id])){
            //We remove Ci' from the solution
            for(int ci_id = 0; ci_id < ci.size(); ci_id++){
                solution.erase(remove(solution.begin(), solution.end(), ci[ci_id]), solution.end());
            }

            //We remove iPrime from the solution
            solution.erase(remove(solution.begin(), solution.end(), iPrime), solution.end());

            //We add the new interval to the solution
            solution.push_back(&omega[omega_id]);
        }
    }
    
    return solution;
}

/**
 * @brief Finds the Qi list of intervals (every interval that intersects with the current interval)
 * 
 * @param omega_id Id of the interval in the omega list
 */
void Greedy::findQi(int omega_id){
    //We first remove the old Qi list
    qi.clear();
    //We also clear iPrime
    iPrime = NULL;

    // [PRINT] // cout << "i : ";
    // [PRINT] // omega[omega_id].printInterval();

    for(int solution_id = 0; solution_id < solution.size(); solution_id++){
        // We add the conflicting intervals to the Qi list
        if((omega[omega_id].getStartDate() < solution[solution_id]->getStopDate() &&  omega[omega_id].getStopDate() > solution[solution_id]->getStartDate() )
        || ( omega[omega_id].getStopDate() > solution[solution_id]->getStartDate() && omega[omega_id].getStartDate() < solution[solution_id]->getStopDate())){
            qi.push_back(&omega[omega_id]);
            // [PRINT] // solution[solution_id]->printInterval();
        }

        // We find iPrime
        if(omega[omega_id].getHashcode() == solution[solution_id]->getHashcode()){
            iPrime = &omega[omega_id];
            // [PRINT] // iPrime->printInterval();
        }
    }

    // [PRINT] // cout << "Qi: " << qi.size() << endl;
}

/**
 * @brief Finds and initiates the points of the Qi list
 * 
 */
void Greedy::findPoints(){
    //We first remove the old points
    points.clear();

    //We initialize the first and last vectors with -1
    first = vector<short>(qi.size(), -1);
    last = vector<short>(qi.size(), -1);

    //We try to find a point at every interval
    for (int currentPointId = 0; currentPointId < qi.size(); currentPointId++){
        vector<short> crossedIntervals;

        //Temporary copies of first and last
        vector<short> firstTemp = first;
        vector<short> lastTemp = last;

        //We check every interval after the current one to see if the point crosses more than "m"
        for(int qId = currentPointId; qId < qi.size(); qId++){
            //If the point crosses an interval, we add it to the crossedIntervals vector
            if(qi[currentPointId]->getStopDate() > qi[qId]->getStartDate()){
                crossedIntervals.push_back(qId);

                //We update the temporary first and last vectors
                //First is only updated if there isn't already a value
                if(firstTemp[qId] == -1){
                    firstTemp[qId] = currentPointId;
                }
                lastTemp[qId] = currentPointId;
            }
        }

        //If the point crosses more than "m" intervals, we update the first and last vectors and validate the point
        if(crossedIntervals.size() >= maxChannel){
            points.push_back(Point(currentPointId));

            first = firstTemp;
            last = lastTemp;
        }
    }
    // [PRINT] // cout << "Points: " << points.size() << endl;
}

/**
 * @brief Finds the Ci list of intervals (minimal cost of the Qi list)
 * 
 * @param pointId Id of the point in the points list
 */
void Greedy::findCi(){
    //We first remove the old Ci list
    ci.clear();

    //We set every cost to max value of a short
    for(int pointId = 0; pointId < points.size(); pointId++){
        points[pointId].setCost(32767);
    }

    for (int qiId = 0; qiId < qi.size(); qiId++){
        //We check if the interval is crossed by a point
        if(first[qiId] != -1){
            //We iterate over the points that cross the interval
            for(int pointId = first[qiId]; pointId <= last[qiId]; pointId++){
                //We update the cost of the point and keep track of the minimal cost interval crossed by the point
                if(points[first[qiId]-1].getCost() + qi[qiId]->getWeight() < points[pointId].getCost()){ //TODO: handle the case where the point is the first one and we try to access the previous one going out of bounds
                    points[pointId].setCost(points[first[qiId]-1].getCost() + qi[qiId]->getWeight());
                    points[pointId].setMinInterval( (short) qiId);
                }
            }
        }
    }
}


/**
 * @brief Checks if the exchange of Ci' (Ci + i') by i is worth it
 * 
 * @return true If the exchange is worth it
 * @return false If the exchange is not worth it
 */
bool Greedy::exchangeCheck(Interval *i){

    //The two weights we need for the comparison
    short ciWeight;
    short iPrimeWeigh;
    
    //We get the cost of the last point (Corresponding to the weight of ci)
    if (points.size() > 0)
        ciWeight = points[points.size()-1].getCost();
    //If there are no points, there are no conflicts,the weight of ci is 0
    else
        ciWeight = 0;

    //We get the weight of iPrime
    if (iPrime != NULL)
        iPrimeWeigh = iPrime->getWeight();
    //If iPrime is NULL, there is no iPrime, the weight of iPrime is 0   
    else
        iPrimeWeigh = 0;

    // [PRINT] // cout << "Ci weight: " << ciWeight << endl;
    // [PRINT] // cout << "iPrime weight: " << iPrimeWeigh << endl;
    // [PRINT] // cout << "i weight: " << i->getWeight() << endl;

    //We check if the exchange is worth it 
    if (ciWeight + iPrimeWeigh <= alpha * i->getWeight()){
        // [PRINT] // cout << "Exchange is worth it" << endl;
        return true;
    }
    // [PRINT] // cout << "Exchange is not worth it" << endl;
    return false;
}

