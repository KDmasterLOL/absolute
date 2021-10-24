#pragma once
class ConsoleGame
{

protected:
    ConsoleGame() {}
    ~ConsoleGame() {}
    virtual void Init()
    {
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
    }
    void Draw()
    {
    }
    void DrawMap()
    {
    }
    void DrawCharacter() {}
    void CheckHit() {}
    virtual void RunCycle() {}
};