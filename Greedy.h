#pragma once
#include "Interval.h"
#include "Point.h"
#include <vector>
#include <algorithm>

using namespace std;

class Greedy{
private:
    vector<Interval> omega; /** < List of all intervals*/
    vector<Interval *> solution; /** < Current solution*/
    vector<Interval *> qi; /** < List of conflicting intervals*/
    vector<Interval *> ci; /** < List of minimal cost conflicting intervals*/
    Interval * iPrime;  /** < Interval belonging to the same job as i*/
    vector<Point> points; /** < List of all points*/
    vector<short> first; /** < List of first point for each interval*/
    vector<short> last; /** < List of last point for each interval*/
    short maxChannel; /** < Max number of channels*/
    float alpha; /** < Alpha value*/

public:
    Greedy();
    Greedy(vector<Interval> omega, short maxChannel, float alpha);

    void setOmega(vector<Interval> omega);
    void setMaxChannel(short maxChannel);
    void setAlpha(float alpha);

    void findQi(int omega_id);
    void findPoints();
    void findCi();
    bool exchangeCheck(Interval * i);

    vector<Interval *> solve();
};
