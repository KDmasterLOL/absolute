#pragma once

class CommandConsoleGame final : public Command
{
private:
    
    map<shared_ptr<positionObject>, entityObject> objects_postions;

public:
    CommandConsoleGame() : Command("Console game")
    {
    }
    ~CommandConsoleGame() {}
    void Run() override
    {
        
        
        clear();
        endwin();
    }
    

};

using command_console_game = unique_ptr<CommandConsoleGame>;