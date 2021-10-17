#pragma once

class CommandConsoleGame : public Command
{
private:
public:
    CommandConsoleGame() : Command("Console game")
    {
    }
    ~CommandConsoleGame() {}
    void Run() override
    {
        initscr();
        raw();
        keypad(stdscr, TRUE);
        printw("You");
        refresh();
        int key = 0;
        while (!(key == 'e'))
        {
            key = getch();
            printw("Your key: %i/n", key);
            refresh();
        }
        endwin();
    }
};

using command_console_game = unique_ptr<CommandConsoleGame>;