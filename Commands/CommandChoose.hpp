#pragma once

// Takes vector of Command and wait input number Command and run that
class CommandChoose : public Command
{
    vector<command_ptr> commands;

public:
    CommandChoose(vector<command_ptr> commands)
        : Command("Command choose"), commands(std::move(commands)) {}

    CommandChoose(const CommandChoose &) = delete;
    void Run()
    {
    }
    void ShowCommands()
    {
        for (const auto &command : commands)
        {
            int index = 1;
            cout << index << ". " << command;
        }
    }
    void WaitingInput()
    {
        int index;
        cin >> index;
        index--;
        commands.at(index);
    }
    void RunCycle()
    {
        while (cin)
        {
            try{
            cout << "Choose command:" << endl;
            ShowCommands();
            WaitingInput();
            }
            catch (){}
        }
    }
};

using command_choose_ptr = unique_ptr<CommandChoose>;
