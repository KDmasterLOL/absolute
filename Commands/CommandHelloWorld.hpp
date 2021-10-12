#include "Commands/Command.hpp"

class CommandHelloWorld : public Command
{
    public:
    CommandHelloWorld() : Command("Hello world") {}
    void Run(){
        cout << "Hello world!!!";
    }
};