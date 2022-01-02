#pragma once

class CommandConsoleGame final : public Command
{
private:
    

public:
    CommandConsoleGame() : Command("Console game")
    {
    }
    ~CommandConsoleGame() {}
    void Run() override
    {
        
    }
    

};

using command_console_game = unique_ptr<CommandConsoleGame>;