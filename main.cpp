#include "Commands/Commands.hpp"

// Entry point
int main()
{
    vector<command_ptr> commands;
    commands.push_back(make_unique<CommandHelloWorld>());
    command_choose_ptr choose = make_unique<CommandChoose>(move(commands));
    choose->Run();
}