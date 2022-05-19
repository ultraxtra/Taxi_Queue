#include "People.h"
#include <iostream>
#include <time.h>

using namespace std;
//*-------------------------------------

#include "People.h"

People::People()
{
    this->tCome = 0;
}

People::~People()
{
}

Peoples::Peoples()
{
    this->countPeople = 0;
    this->waitBigData = 0;
    this->countBigData = 0;
}

Peoples::~Peoples()
{
}

enum PART_OF_DAY { Night = 0, Morning, Day, Evening };

//*---------------------------------------------
int Peoples::getIntervalByPartDay(int t) {
    int min, max;
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
        min = 0; max = 1;
        break;
    case Morning:
        min = 1; max = 5;
        break;
    case Day:
        min = 2; max = 5;
        break;
    case Evening:
        min = 3; max = 5;
        break;
    default:
        min = 0; max = 0;
        break;
    }
    return rand() % max + min;
}