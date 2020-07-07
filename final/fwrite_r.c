#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    FILE *fp = fopen("test", "w+");
    char *msg = "hello";
    char *buf = malloc(100);
    read(0, buf, 100);

    fp->_flags &= ~8;
    fp->_flags |= 0x800;
    fp->_flags |= _IO_IS_APPENDING;

    fp->_IO_write_base = msg;
    fp->_IO_write_ptr = msg + 5;
    fp->_fileno = 1;

    fwrite(buf, 1, 5, fp);
}
