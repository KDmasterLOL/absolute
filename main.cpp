#include"Commands/Commands.hpp"
// Entry point
int main(){
    Command *command = new CommandHelloWorld();
    command->Run();
    exit(0);
}
