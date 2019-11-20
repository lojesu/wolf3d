#include <libft.h>
#include <wolf3d.h>
#include <unistd.h>
#include <fcntl.h>
#include <vector.h>

#define BUFF_SIZE (BMP_SIZE * 3)

static int  rgb_to_hex(uint8_t r, uint8_t g, uint8_t b)
{
        return (b << 16 ^ g << 8 ^ r);
}

static void read_bmp(int ret[BMP_SIZE], char *path)
{
    char buff[BUFF_SIZE + 1];
    t_vec bmp;
    int fd;
    size_t start;
    size_t i;
    int tmp = 0;

    bmp = v_new(sizeof(uint8_t));
    if ((fd = open(path, O_RDONLY)) == -1)
        return ;
    while ((tmp = read(fd, buff, BUFF_SIZE)) > 0)
        v_append_raw(&bmp, buff, tmp);
    start = v_size(&bmp) - BUFF_SIZE;
    i = 0;
    while (start + i < v_size(&bmp))
    {
        ret[i / 3] = rgb_to_hex(*(char *)v_get(&bmp, i + start),
                        *(char *)v_get(&bmp, i + 1 + start),
                        *(char *)v_get(&bmp, i + 2 + start));
        i += 3;
    }
    v_del(&bmp);
    close(fd);
}

void        my_intcpy(int *dst, int *src, int size)
{
        int i = 0;

        while (i < size)
        {
            dst[i] = src[i];
            ++i;
        }
}

void        launch_texture(t_env *env)
{
    int     bmp[BMP_SIZE];
    char    *path[BMP_NB];
    int i;

    path[0] = "textures/banane_noire64.bmp";
    path[1] = "textures/banane_noire64.bmp";
    path[2] = "textures/banane_noire64.bmp";
    path[3] = "textures/banane_noire64.bmp";
    i = 0;
    while (i < BMP_NB)
    {
        ft_bzero(bmp, BMP_SIZE);
        read_bmp(bmp, path[i]);
        my_intcpy(env->bmp[i], bmp, BMP_SIZE);
        ++i;
    }
}
