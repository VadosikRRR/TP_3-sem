#include <cstdlib> // Для system()
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct winsize size;
    size.ws_row = 80;
    size.ws_col = 40;

    ioctl(STDOUT_FILENO, TIOCSWINSZ, &size);
    // Открываем новое окно терминала и выполняем команду
    system("gnome-terminal -- bash -c 'echo \"Это новое окно терминала!\"; exec bash'");

    return 0;
}