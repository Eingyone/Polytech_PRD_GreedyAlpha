#include "Interval.h"

/****************************************************************************
 * Constructors / Destructors
 ****************************************************************************/

/**
 * @brief Construct a new Interval:: Interval object
 * 
 */
Interval::Interval()
{
    id = 0;
    startDate = 0;
    stopDate = 0;
    channel = "";
    hashcode = "";
    weight = 0;
    //pointList = new short[0];
}

/**
 * @brief Construct a new Interval:: Interval object
 * 
 * @param id Interval id
 * @param startDate Interval start date
 * @param stopDate Interval stop date
 * @param channel Interval channel
 * @param hashcode Interval hashcode
 */
/***/
Interval::Interval(short id, long long startDate, long long stopDate, string channel, string hashcode){
    this->id = id;
    this->startDate = startDate;
    this->stopDate = stopDate;
    this->channel = channel;
    this->hashcode = hashcode;
    this->weight = 0;
    //pointList = new short[0];
}

/****************************************************************************
 * Getters / Setters
 ****************************************************************************/

/**
 * @brief Gets the id of the interval
 * 
 * @return short Id of the interval
 */
short Interval::getId(){
    return id;
}

/**
 * @brief Gets the start date of the interval
 * 
 * @return long Start date of the interval
 */
long long Interval::getStartDate(){
    return startDate;
}

/**
 * @brief Gets the stop date of the interval
 * 
 * @return long Stop date of the interval
 */
long long Interval::getStopDate(){
    return stopDate;
}

/**
 * @brief Gets the channel of the interval
 * 
 * @return short Channel of the interval
 */

string Interval::getChannel(){
    return channel;
}

/**
 * @brief Gets the hashcode of the interval
 * 
 * @return char* Hashcode of the interval
 */
string Interval::getHashcode(){
    return hashcode;
}

/**
 * @brief Gets the weight of the interval
 * 
 * @return short Weight of the interval
 */
short Interval::getWeight(){
    return weight;
}

/**
 * @brief Sets the start date of the interval
 * 
 * @param startDate Start date of the interval
 */
void Interval::setStartDate(long long startDate){
    this->startDate = startDate;
}

/**
 * @brief Sets the stop date of the interval
 * 
 * @param stopDate Stop date of the interval
 */
void Interval::setStopDate(long long stopDate){
    this->stopDate = stopDate;
}

/****************************************************************************
 * Methods
 ****************************************************************************/

/**
 * @brief Generates a random weight for the interval using its hashcode
 * 
 */
void Interval::generateRandomWeight(){
    short random_weight = 0;
    //we iterate over the hashcode to generate a random weight using the char values
    for(int i = 0; i < sizeof(hashcode); i++){
        random_weight = random_weight + (short) hashcode[i];
    }
    this->weight = random_weight;
}

/**
 * @brief Prints the interval
 * 
 */
void Interval::printInterval(){
    std::cout << "Interval " << id << " : " << startDate << " - " << stopDate << " on channel " << channel << " with hashcode " << hashcode << " and weight " << weight << std::endl;
}