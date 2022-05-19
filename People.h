#pragma once

#pragma once
#include <iostream>

using namespace std;

class People
{
public:
    People();
    People(int t) : People() { this->tCome = t; };
    ~People();

    People* next;

    int tCome; 

    bool add(int t)
    {
        if (this->next != nullptr)
        {
            this->next->add(t);
        }
        else
        {
            this->next = new People(t);
        }
        return true;

    }
};

class Peoples
{
public:
    Peoples();
    ~Peoples();

    People* root;
    int countPeople;
    int countBigData;  // количество народу , которые уехали
    int waitBigData;   // Общее время ожидания в минутах

    //*---------------------------------------------------

    bool remove(int t) {
        if (this->root == nullptr) { return false; }
        People* tmp = this->root->next;
        this->countBigData++;
        this->countPeople--;
        this->waitBigData = this->waitBigData + (t - this->root->tCome);
        cout << t - this->root->tCome << " (" << this->waitBigData << " ) , ";
        delete this->root;
        this->root = tmp;
        return true;

    }
    //*-----------------------------------------------------------------

    bool away(int t, int c)
    {
        cout << "\n\t + Went:  ";
        for (int i = 0; i < c; i++)
        {
            this->remove(t);
        }
        return true;
    }

    //*------------------------------------------------------------------

    bool add(int t)
    {
        if (this->root != nullptr)
        {
            this->root->add(t);
        }
        else
        {
            this->root = new People(t);
        }
        this->countPeople++;
        return this->countPeople;
    }
    //*------------------------------------------------------------------------

    bool comeToBusStop(int t, int dt) {
        int k = getIntervalByPartDay(t);
        cout << "\n\t ! on the bus stop " << k;
        for (int i = 0; i < k; i++)
        {
            this->add(t);
        }
        return true;
    }

    int getIntervalByPartDay(int); 

private:

};