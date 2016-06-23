#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
//    char buffer[BUFFER_SIZE];
//    bzero((void*)buffer, sizeof(char) * BUFFER_SIZE);

    mkfifo("/home/kisselev/Kurs/5/543/fifo/in.fifo", 0666);
    int in = open("/home/kisselev/Kurs/5/543/fifo/in.fifo", O_RDONLY | O_NONBLOCK, 066);


    mkfifo("/home/kisselev/Kurs/5/543/fifo/our.fifo", 0666);
    int out = open("/home/kisselev/Kurs/5/543/fifo/out.fifo", O_WRONLY | O_NONBLOCK, 066);

    close(out);
    dup2(in, out);
    close(in);


    return 0;
}

