#include "ft_ls.h"

int max_links(t_dir *dir)
{
    struct stat file_stat;
    int n;

    n = 0;
    while (dir)
    {
        stat(dir->str, &file_stat);
        n = (n < file_stat.st_nlink ? file_stat.st_nlink : n);
        dir = dir->next;
    }
    return (n);
}

