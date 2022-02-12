#pragma once

// Takes vector of Command and wait input number Command and run that
class CommandChoose final : public Command, public NcursesClasses::NcursesGraphics
{
    vector<command_ptr> commands;
    stringstream s_str;
    bool play = true, not_valid_index = false;

public:
    CommandChoose(vector<command_ptr> commands)
        : Command("Command choose"s), commands(std::move(commands))
    {
        this->commands.push_back(make_unique<CommandExit>(&play));
    }

    CommandChoose(const CommandChoose &) = delete;
    void run() override
    {
        runCycle();
    }
    void showCommands()
    {
        for (size_t index = 0; index < commands.size(); index++)
            s_str << index + 1 << ". " << commands[index] << endl;
    }
    void processingInput()
    {
        int index;
        char *str = new char[32];
        // mvgetstr(, , str);

        index = atoi(str);

        // Input more by one
        if (index < 1 || index > commands.size())
            throw out_of_range(std::to_string(index));
        else
        {
            endCurses();
            commands[--index]->run();
        }
    }
    void initText()
    {
        s_str.clear();
        s_str << "Choose command:" << endl;
        showCommands();
        s_str << "Your enter - ";
    }
    void runCycle()
    {
        initCurses();
        initText();
        while (play)
        {
            try
            {
                clear();
                printw(s_str.str().c_str());

                refresh();
                processingInput();
            }
            catch (out_of_range exc)
            {
                if (!not_valid_index)
                    s_str << endl
                          << "You enter not valid index! - (" << exc.what() << ")" << endl;
                not_valid_index = true;
            }
        }
        endCurses();
    }
    void pipelineDraw() override
    {
        
    }
};

using command_choose_ptr = unique_ptr<CommandChoose>;