namespace NcursesClasses
{
    class NcursesGraphics
    {
    private:
        size_t console_size_y, console_size_x;
        std::map<string, NcursesStructures::position> points;
        // std::multimap<
    protected:
    public:
        NcursesGraphics(){};
        virtual ~NcursesGraphics(){};
        void initCurses()
        {
            initscr();
            configureCurses();
            points.clear();
            getmaxyx(stdscr, console_size_y, console_size_x);
        }
        virtual void configureCurses()
        {
            cbreak();
        }
        virtual void pipelineDraw()
        {
            /* 
            
             */
        }
        
        void setPoint(string name)
        {
            NcursesStructures::position pos;
            getyx(stdscr, pos.y, pos.x);
            points.insert({move(name), move(pos)});
        }
        virtual void endCurses() { endwin(); }
    };
}