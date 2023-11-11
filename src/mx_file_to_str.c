#include "libmx.h"

static int len(const char *file) {
    short fileStatus = open(file, O_RDONLY);
    short sz = 0;
    int len = 0;
    char buffer;

    sz = read(fileStatus, &buffer, 1);
    while (sz > 0)
    {
        sz = read(fileStatus, &buffer, 1);
        len++;
    }
    close(fileStatus);
    return len;
}

char *mx_file_to_str(const char *file)
{
    int fileStatus = open(file, O_RDONLY);
    int size = 0;
    if (fileStatus == -1)
    {
        close(fileStatus);
        return NULL;
    }
    size = len(file);
    if (size == 0)
    {
        return NULL;
    }
    char *newStr = mx_strnew(size);
    close(fileStatus);
    return newStr;
}
