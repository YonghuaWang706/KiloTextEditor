#include <unistd.h>
#include <stdio.h>
#include <termios.h>
//turn off echoing
//echo: each key you type to be printed to the terminal
void enableRawMode() {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag &= ~(ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'){
        //printf("input char: %c\n", c);
    }
    return 0;
}