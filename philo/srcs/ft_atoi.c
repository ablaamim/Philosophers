#include "../includes/philosophers.h"

int ft_atoi(char *argv)
{
    int res;
    int sign;

    res = 0x0;
    sign = 0x1;
    while ((*argv >= 7 && *argv <= 14) || *argv == 32)
        argv++;
    if (*argv == '-')
        sign *= -1;
    if (*argv == '+' || *argv == '-')
        argv++;
    while (*argv && (*argv >= 48 && *argv <= 57))
    {
        res = res * 10 + *argv - 48;
        argv++;
    }
    return (sign * res);
}