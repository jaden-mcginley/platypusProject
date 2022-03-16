/*
    File Name: wk11_platypus_jmcginley.h
    Summary: A header file for a Platypus class.
    Author: Jaden McGinley
    Created: Mar 8, 2022
    Summary of Modifications:
        Mar 8, 2022 - JM - created the program
*/

#ifndef PLATYPUS_H
#define PLATYPUS_H
#pragma once

#include <iostream>

class Platypus
{
    public:
        //constructors
        Platypus();
        Platypus(std::string Name, short int Age, char Gender, float Weight, bool Alive = true, bool Mutant = false);
        static Platypus initiate_Birth();

        //destructors
        ~Platypus();

        //mutators
        void set_Name(std::string Name);
        void set_Age(short int Age);
        void set_Gender(char Gender);
        void set_Weight(float Weight);
        void set_Alive(bool Alive);
        void set_Mutant(bool Mutant);

        //accessors
        std::string get_Name();
        short int get_Age();
        char get_Gender();
        float get_Weight();
        bool get_Alive();
        bool get_Mutant();

        //others
        //functions go here...
        void print_Information();
        void increment_Age();
        void increment_Weight();
        void initiate_Fight(Platypus victim);
    private:
        std::string name;
        short int age; //months
        char gender; //m/f
        float weight; //pounds
        bool alive;
        bool mutant;
};

#endif