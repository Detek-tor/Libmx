#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *mem = NULL;
    int i = 0;
    int j = 0;
		char *tmp = NULL;
    if (!str) return NULL;
    mem = mx_strnew(mx_strlen(str));
    while (str[i])
    {
        if (!(mx_isspace(str[i])))
        {
            mem[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1]))
        {
            mem[j] = ' ';
            j++;
        }
        i++;
    }
    tmp = mx_strtrim(mem);
    mx_strdel(&mem);
    return tmp;
}
