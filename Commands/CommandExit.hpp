#pragma once
class CommandExit final : public Command
{
    bool *play = nullptr;

public:
    CommandExit(bool *play = nullptr) : Command("Exit"), play(play) {}
    void Run() override
    {
        if (play != nullptr)
            *play = false;
        else
        {
            exit(EXIT_SUCCESS);
        }
    }
};