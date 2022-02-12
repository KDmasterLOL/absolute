#include "Commands/Commands.hpp"

// Entry point
int main()
{
    vector<command_ptr> v_commands;
    v_commands.push_back(make_unique<CommandHelloWorld>());
    v_commands.push_back(make_unique<CommandConsoleGame>());
    command_choose_ptr up_choose = make_unique<CommandChoose>(move(v_commands));
    up_choose->run();
    exit(EXIT_SUCCESS);
}