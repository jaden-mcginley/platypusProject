/*
    File Name: wk11_platypusDriver_jmcginley.cpp
    Summary: A driver file for a Platypus class.
    Author: Jaden McGinley
    Created: Mar 8, 2022
    Summary of Modifications:
        Mar 8, 2022 - JM - created the program
*/
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "E:\Programming\VSC\SchoolApplications\C++\CS162\Week 11\Platypus\wk11_platypus_jmcginley.h"
#include "E:\Programming\VSC\SchoolApplications\C++\CS162\Week 11\Platypus\wk11_platypus_jmcginley.cpp"

using namespace std;

int main()
{
    void pass_Year(Platypus platypus);
    srand(time(NULL));

    Platypus platypus_1;
    platypus_1.print_Information();

    Platypus platypus_2("Perry", 2, 'm', .52);
    cout << "\n";
    platypus_2.print_Information();

    Platypus platypus_3(Platypus::initiate_Birth());
    cout << "\n";
    platypus_3.print_Information();

    pass_Year(platypus_1);
    return 0;
}

void pass_Year(Platypus platypus)
{
    platypus.increment_Weight();
    platypus.initiate_Fight(Platypus::initiate_Birth());

    if(platypus.get_Alive())
    {
        platypus.increment_Age();
    }
    else
    {
        cout << platypus.get_Name() << " survived " << platypus.get_Age() << " month(s).\n";
    }
    return;
}