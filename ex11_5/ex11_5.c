#include <io.h>
#if !defined(__TINY__) && !defined(__SMALL__) && !defined(__MEDIUM__)
#error Use tiny, small or medium memory model.
#endif

#include <alloc.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int src, dest;
    unsigned memfree;
    long filesize;
    void *buf;
    long i;

    if (argc != 3) {
        printf("USAGE : ex11_5 filename1 filename2\n");

        return 0;
    }

    if ((src = open(argv[1], O_RDONLY | O_BINARY)) == -1) {
        printf("File open error : %s\n", argv[1]);

        return 0;
    }

    dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | O_BINARY,
                S_IREAD | S_IWRITE);

    if (dest == -1) {
        printf("File creation error : %s\n", argv[2]);

        return 0;
    }

    printf("Copy %s to %s\n", argv[1], argv[2]);
    memfree = coreleft();
    buf = malloc(memfree);

    if (buf == NULL) {
        printf("Memory allocation error\n");

        return 0;
    }

    filesize = filelength(src);

    for (i = 0; i < filesize / memfree; i++) {
        read(src, buf, memfree);
        write(dest, buf, memfree);
    }

    read(src, buf, filesize % memfree);
    write(dest, buf, filesize % memfree);
    close(src);
    close(dest);

    return 0;
}
