#pragma once

// Takes vector of Command and wait input number Command and run that
class CommandChoose final : public Command
{
    vector<command_ptr> commands;
    bool play = true;

public:
    CommandChoose(vector<command_ptr> commands)
        : Command("Command choose"), commands(std::move(commands))
    {
        this->commands.push_back(make_unique<CommandExit>(&play));
    }

    CommandChoose(const CommandChoose &) = delete;
    void Run() override
    {
        RunCycle();
    }
    void ShowCommands()
    {
        int index = 1;
        for (const auto &command : commands)
        {
            cout << index++ << ". " << command << endl;
        }
    }
    void WaitingInput()
    {
        int index;
        cin >> index;
        index--;
        commands.at(index)->Run();
    }
    void RunCycle()
    {
        system("clear");
        cin.exceptions(std::iostream::badbit | std::iostream::failbit);
        while (play)
        {
            try
            {
                cout << "Choose command:" << endl;
                ShowCommands();
                cout << "Your enter - ";
                WaitingInput();
            }
            catch (out_of_range)
            {
                cout << "You enter not valid index" << endl;
            }
            catch (iostream::failure)
            {
                cout << "Enter number!!!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
};

using command_choose_ptr = unique_ptr<CommandChoose>;
