#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "error_functions.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int
main(int argc, char *argv[])
{
    bool    isAppend;
    int     opt;
    int     outputFd, outputFlags, outputPerms;
    ssize_t numRead;
    char    buf[BUF_SIZE];

    isAppend = false;

    while ((opt = getopt(argc, argv, "a")) != -1) {
        switch (opt) {
            case 'a':
                isAppend = true;
                break;
            default:
                break;
        }
    }

    outputFlags = O_CREAT | O_WRONLY | (isAppend ? O_APPEND : O_TRUNC);
    outputPerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                  S_IROTH | S_IWOTH;      /* rw-rw-rw- */
    outputFd = open(argv[optind], outputFlags, outputPerms);
    if (outputFd == -1) {
        errExit("opening file %s", argv[1]);
    }

    while ((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, numRead) != numRead) {
            fatal("couldn't write whole buffer");
        }
        if (write(outputFd, buf, numRead) != numRead) {
            fatal("couldn't write whole buffer");
        }
    }

    if (close(outputFd) == -1) {
        errExit("close output");
    }

    exit(EXIT_SUCCESS);
}
