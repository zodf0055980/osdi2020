#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    FILE *fp = fopen("test", "rw");
    char *buf = malloc(100);
    char msg[100];
    memset(msg, 0, 100);

    fp->_flags &= 4;
    fp->_IO_buf_base = msg;
    fp->_IO_buf_end = msg + 100;
    fp->_fileno = 0;

    printf("msg = %s\n", msg);
    fread(buf, 1, 6, fp);
    printf("msg = %s\n", msg);
}