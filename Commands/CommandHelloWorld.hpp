#pragma once

// Output: Constructor - "WTF", Destructor - "Bye world", Run - Hello world

class CommandHelloWorld : public Command
{
public:
    CommandHelloWorld() : Command("Hello world") { cout << "WTF" << endl; }
    ~CommandHelloWorld() { cout << "Bye world" << endl; }
    void Run() override
    {
        cout << "Hello world!!!" << endl;
    }
};

using command_hello_world_ptr = unique_ptr<CommandHelloWorld>;