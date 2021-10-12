#pragma once
#include "Utils/Common.hpp"
class Command
{
    string name;
    public:   
    Command(string name) : name(name) {}
    virtual void Run() {}
    void ShowName() { cout << "Command name: " << name; }
};