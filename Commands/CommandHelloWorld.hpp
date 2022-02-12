#pragma once

// Output: Constructor - "WTF", Destructor - "Bye world", Run - Hello world

class CommandHelloWorld final : public Command
{
public:
    CommandHelloWorld() : Command("Hello world"s) {}
    void run() override
    {
        cout << "Hello world!!!" << endl;
    }
};

using command_hello_world_ptr = unique_ptr<CommandHelloWorld>;