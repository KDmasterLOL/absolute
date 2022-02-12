#pragma once
class ConsoleGame
{
private:
    int console_size_x, console_size_y;

protected:
    ConsoleGame() {}
    ~ConsoleGame() {}
    virtual void init()
    {
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        getmaxyx(stdscr, console_size_y, console_size_x);
    }
    void draw()
    {
    }
    void drawMap()
    {
    }
    void drawCharacter() {}
    void checkHit() {}
    virtual void runCycle() {}
};