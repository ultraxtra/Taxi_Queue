#include "BusStop.h"
#include "Bus.h"
#include "People.h"


#include <iostream>
#include <string>
#include <time.h>
using namespace std;


BusStop::BusStop()
{
    this->peoples = new Peoples;
}


BusStop::~BusStop()
{
}

bool BusStop::CreateBus(int count) {
    int in[4];
    this->bus = new Bus[count];
    for (int i = 0; i < count; i++)
    {
        in[0] = rand() % 30 + 30;
        in[1] = rand() % 10 + 10;
        in[2] = rand() % 10 + 15;
        in[3] = rand() % 10 + 10;
    }
    this->countBus = count;
    return true;
}

//-----------------------------------------------------------

bool BusStop::mainLoop() {
    int mest;
    for (int t = 0; t < 60 * 24; t++)
    {
        cout << ".";
      
        this->peoples->comeToBusStop(t, 1);

        for (int b = 0; b < countBus; b++)
        {
            mest = this->bus[b].comeToBusStop(t, 1);
            if (mest > 0) {
                cout << "\n" << t << "-->Autobus № " << this->bus[b].getNumber() << " Free places " << mest <<
                    " On the bus stop " << this->peoples->countPeople;
                this->peoples->away(t, mest);
                cout << "/" << " Left " << this->peoples->countPeople;
            }
        }
    }

    cout << "\n\n---Statistics---";
    cout << "\n Passangers: " << this->peoples->countBigData;
    cout << "\n Lost time " << this->peoples->waitBigData;
    cout << "\n Average time: " << (double)this->peoples->waitBigData / this->peoples->countBigData;
    return true;
}