/*
    File Name: wk11_platypus_jmcginley.cpp
    Summary: An implementation file for a Platypus class.
    Author: Jaden McGinley
    Created: Mar 8, 2022
    Summary of Modifications:
        Mar 8, 2022 - JM - created the program
*/

#include <iostream>
#include <iomanip>
#include <random>
#include <fstream>
#include <string>

#include "E:\Programming\VSC\SchoolApplications\C++\CS162\Week 11\Platypus\wk11_platypus_jmcginley.h"

std::string m_Names_FileDirectory = "E:/Programming/VSC/SchoolApplications/C++/Documents/m_Names.txt";
std::string f_Names_FileDirectory = "E:/Programming/VSC/SchoolApplications/C++/Documents/f_Names.txt";

std::string determine_Name(char Gender_);

//constructors
Platypus::Platypus()
{
    name = "Platypus";
    age = 0;
    gender = 'f';
    weight = .18;
    alive = true;
    mutant = false;
}

Platypus::Platypus(std::string Name, short int Age, char Gender, float Weight, bool Alive, bool Mutant)
{
    name = Name;
    age = Age;
    gender = Gender;
    weight = Weight;
    alive = Alive;
    mutant = Mutant;
}

Platypus Platypus::initiate_Birth()
{
    std::string Name;
    char Gender;
    float Weight = static_cast<float>((rand() % 11 + 1)) / 10;

    bool determineGender = (rand() % 100) < 50;
    if (determineGender)
    {
        Gender = 'm';
    }
    else
    {
        Gender = 'f';
    }

    Name = determine_Name(Gender);

    return Platypus(Name, 0, Gender, Weight);
}

//destructor
Platypus::~Platypus()
{

}

//mutators
void Platypus::set_Name(std::string Name)
{
    name = Name;
}

void Platypus::set_Age(short int Age)
{
    age = Age;
}

void Platypus::set_Gender(char Gender)
{
    gender = Gender;
}

void Platypus::set_Weight(float Weight)
{
    weight = Weight;
}

void Platypus::set_Alive(bool Alive)
{
    alive = Alive;
}

void Platypus::set_Mutant(bool Mutant)
{
    mutant = Mutant;
}

//accessors
std::string Platypus::get_Name()
{
    return name;
}

short int Platypus::get_Age()
{
    return age;
}

char Platypus::get_Gender()
{
    return gender;
}

float Platypus::get_Weight()
{
    return weight;
}

bool Platypus::get_Alive()
{
    return alive;
}

bool Platypus::get_Mutant()
{
    return mutant;
}

//others
void Platypus::print_Information()
{
    char aliveChar;
    switch(alive)
    {
        case true:
            aliveChar = 't';
            break;
        case false:
            aliveChar = 'f';
            break;
    }

    char mutantChar;
    switch(mutant)
    {
        case true:
            mutantChar = 't';
            break;
        case false:
            mutantChar = 'f';
            break;
    }

    std::cout << std::left << std::setfill('#') << std::setw(90) << "#";
    std::cout << std::setfill(' ') << std::endl;

    std::cout << "\t\t\t\tPlatypus Information..." << std::endl;

    std::cout << std::left << std::setfill('#') << std::setw(90) << "#";
    std::cout << std::setfill(' ') << std::endl;

    std::cout << std::left << std::setw(15) << "NAME"
              << std::setw(15) << "AGE"
              << std::setw(15) << "GENDER"
              << std::setw(15) << "WEIGHT"
              << std::setw(15) << "ALIVE"
              << std::setw(15) << "MUTANT" << std::endl;

    std::cout << std::left << std::setfill('#') << std::setw(90) << "#";
    std::cout << std::setfill(' ') << std::endl;

    std::cout << std::left << std::setw(15) << name
              << std::setw(15) << age
              << std::setw(15) << gender
              << std::setw(15) << weight
              << std::setw(15) << aliveChar
              << std::setw(15) << mutantChar << std::endl;

    std::cout << std::left << std::setfill('#') << std::setw(90) << "#";
    std::cout << std::setfill(' ') << std::endl;
}

void Platypus::increment_Age()
{
    age += 1;

    std::cout << "Platypus " << name << " aged to " << age << " months old." << std::endl;

    bool determineMutant = (rand() % 100) < 2;
    if (mutant != true && determineMutant)
    {
        mutant = true;
        std::cout << "Platypus " << name << " became a mutant." << std::endl;
    }

    bool determineDeath = (rand() % 100) < (weight * 10);
    if (alive != false && determineDeath)
    {
        alive = false;
        std::cout << "Platypus " << name << " died." << std::endl;
    }
}

void Platypus::increment_Weight()
{
    float Weight = static_cast<float>((rand() % 50 + 1)) / ((weight * 10)) / 100;
    weight += Weight;
    std::cout << "Platypus " << name << " ate and gained " << Weight << " pounds.\n";
}

void Platypus::initiate_Fight(Platypus victim)
{
    float fightRatio = (weight/victim.weight) * 50;
    bool determineSurvivor = (rand() % 100) < fightRatio;

    if (determineSurvivor)
    {
        //Calling survives
        victim.alive = false;
        std::cout << "Platypus " << victim.name << " died." << std::endl;
        std::cout << "The platypus " << name << " survived the fight." << std::endl;
    }
    else
    {
        //Victim survives
        alive = false;
        std::cout << "Platypus " << name << " died." << std::endl;
        std::cout << "The platypus " << victim.name << " survived the fight." << std::endl;
    }
}

std::string determine_Name(char Gender_)
{
    std::string Name;
    if (Gender_ == 'f')
    {
        std::ifstream file_(f_Names_FileDirectory);
        if(file_.is_open())
        {
            const int LINE_ = rand() % 51 + 1;
            for (int j = 1; j <= LINE_; j++)
            {
                getline(file_, Name);
            }
        }
        else
        {
            std::cout << "Error! Names file not found!";

            exit(1);
        }

        file_.close();
    }
    
    if (Gender_ == 'm')
    {
        std::ifstream file(m_Names_FileDirectory);
        if(file.is_open())
        {
            const int LINE = rand() % 52 + 1;
            for (int i = 1; i <= LINE; i++)
            {
                getline(file, Name);
            }
        }
        else
        {
            std::cout << "Error! Names file not found!";

            exit(1);
        }

        file.close();
    }

    return Name;
}
