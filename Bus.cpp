#include "Bus.h"

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

Bus::Bus()
{
    this->waitTime = 5;
}


Bus::~Bus()
{
}

//-------------------------------------------------------------------------

bool Bus::changeData(int num, int interval[4]) {
    for (int i = 0; i < 4; i++)
    {
        this->interval[i] = interval[i];
    }
    this->number = num;
    this->max = rand() % 10 + 10;
    return true;
}

enum PART_OF_DAY { Night = 0, Morning, Day, Evening };

//*---------------------------------------------
int Bus::getIntervalByPartDay(int t) {
    int interval;

    PART_OF_DAY vs;

    if (0 < t && t < 420)
    {
        vs = Night;
    }
    else if (420 < t && t < 720) {
        vs = Morning;
    }
    else if (720 < t && t < 1020) {
        vs = Day;
    }
    else {
        vs = Evening;
    }

    switch (vs)
    {
    case Night:
        interval = this->interval[Night];
        break;
    case Morning:
        interval = this->interval[Morning];
        break;
    case Day:
        interval = this->interval[Day];
        break;
    case Evening:
        interval = this->interval[Evening];
        break;
    default:
        interval = 0;
        break;
    }
    return interval;
}

//----------------------------------------------------------

int Bus::comeToBusStop(int t, int dt) {
    this->waitTime = this->waitTime - dt;
    if (this->waitTime > 0) return 0;
    this->waitTime = this->getIntervalByPartDay(t);
    return rand() % this->max + 1;
}