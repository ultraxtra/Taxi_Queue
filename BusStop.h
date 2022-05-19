#pragma once

#pragma once
#include "Bus.h"
#include "People.h"


class BusStop
{
public:
    BusStop();
    ~BusStop();

    bool CreateBus(int);
    Bus* bus;
    int countBus;

    bool mainLoop();
    Peoples* peoples;
};