#pragma once

class Bus
{
    int interval[4]; 
    int waitTime; 
    int max; 
    int number;

public:
    Bus();
    ~Bus();

    bool changeData(int num, int interval[4]);

    int getIntervalByPartDay(int);
    int getNumber() { return this->number; }
    int comeToBusStop(int t, int dt);  
                                      

};