#pragma once
class ConsoleGame
{
private:
    int console_size_x, console_size_y;

protected:
    ConsoleGame() {}
    ~ConsoleGame() {}
    virtual void Init()
    {
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        getmaxyx(stdscr, console_size_y, console_size_x);
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