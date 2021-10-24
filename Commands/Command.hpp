#pragma once
#include "Utils/Common.hpp"
#include "Utils/Ncurses.hpp"
#include "Utils/ConsoleGame.hpp"
// Base class of Commands

class Command
{
    string name;

public:
    Command(string name) : name(name) {}
    virtual ~Command() {}
    virtual void Run() {}
    void ShowName() { cout << "Command name: " << name; }
    friend ostream &operator<<(ostream &out, const Command *command)
    {
        out << command->name;
        return out;
    }
};

using command_ptr = unique_ptr<Command>;