#include<Utils/Common.hpp>
#include<Utils/Ncurses.hpp>

int main(){
    initscr();
    printf("Snake");
    getch();
    endwin();
    return 0;
}