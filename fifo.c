#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	char buffer[BUFFER_SIZE];

    unlink("/home/box/in.fifo");

	int in;

    if (mkfifo("/home/box/in.fifo", 0666) == -1) {
		printf("Error mkfifo in");
	}
    if ((in = open("/home/box/in.fifo", O_RDONLY | O_NONBLOCK, 066)) == -1) {
		printf("Error open fifo in");
	}

    unlink("/home/box/out.fifo");

	int out;

    if (mkfifo("/home/box/out.fifo", 0666) == -1) {
		printf("Error mkfifo out");
	}

    if ((out = open("/home/box/out.fifo", O_WRONLY, 066)) == -1) {
		printf("Error open fifo out");
	}

    //close(out);
    //dup2(in, out);
    //close(in);

    int res = read(in, (void*)buffer, (size_t)BUFFER_SIZE);

    if (res <= 0) {
        printf("Error read");
        close(in);
        close(out);
        return 1;
    }

    res = write(out, buffer, res);

    close(in);
    close(out);

    return 0;
}

