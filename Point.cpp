#include "Point.h"

/****************************************************************************
 * Constructors / Destructors
 ****************************************************************************/

/**
 * @brief Construct a new Point:: Point object
 * 
 */
Point::Point()
{
    id = 0;
    cost = 0;
    minInterval = 0;
}

/**
 * @brief Construct a new Point:: Point object
 * 
 * @param id Point id
 * @param cost Point cost
 */
Point::Point(short id)
{
    this->id = id;
    minInterval = 0;
}

/****************************************************************************
 * Getters / Setters
 ****************************************************************************/

/**
 * @brief Gets the id of the point
 * 
 * @return short Id of the point
 */
short Point::getId(){
    return id;
}

/**
 * @brief Gets the cost of the point
 * 
 * @return short Cost of the point
 */
short Point::getCost(){
    return cost;
}

/**
 * @brief Gets the min interval of the point
 * 
 * @return short Min interval of the point
 */
short Point::getMinInterval(){
    return minInterval;
}

/**
 * @brief Sets the cost of the point
 * 
 * @param cost Cost of the point
 */
void Point::setCost(short cost){
    this->cost = cost;
}

/**
 * @brief Sets the min interval of the point
 * 
 */
void Point::setMinInterval(short minInterval){
    minInterval = 0;
}


