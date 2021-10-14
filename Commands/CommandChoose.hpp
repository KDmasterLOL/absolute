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
        RunCycle();
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
        cin.exceptions(std::iostream::badbit | std::iostream::failbit);
        while (true)
        {
            try
            {
                cout << "Choose command:" << endl;
                ShowCommands();
                WaitingInput();
            }
            catch (out_of_range)
            {
                cout << "You enter not valid index" << endl;
            }
            catch(iostream::failure){
                cout << "Enter number!!!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
};

using command_choose_ptr = unique_ptr<CommandChoose>;
