#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    FILE *fp = fopen("test", "w+");
    char *msg = "hello";
    char *buf = malloc(100);
    fp->_IO_write_end = buf + 5;
    fp->_IO_write_ptr = buf;
    printf("msg = %s\n", buf);
    fwrite(msg, 1, 6, fp);
    printf("msg = %s\n", buf);
}
