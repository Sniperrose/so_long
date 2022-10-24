# include "../include/so_long.h"
# include "../minilibx-linux/mlx.h"


typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double  deltaX;
    double  deltaY;

    deltaX = endX - beginX;
    deltaY = endY - beginY;
    
    int pixels;
    pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

//    printf("deltaX = %f, deltaY = %f, pixels = %d\n\n\n", deltaX, deltaY, pixels);

    deltaX /= pixels;
    deltaY /= pixels;

    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        // printf("after deltaX = %f, deltaY = %f, pixels = %d\n", deltaX, deltaY, pixels);
        mlx_pixel_put(mlx, win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
        
    }
    return (pixels);
}

int draw_box(void *mlx, void *mlx_win, int beginX, int beginY, int delta, int color)
{
    double  deltaX;
    double  deltaY;

    deltaX = delta - beginX;
    deltaY = delta - beginY;

    int pixels;

    double pixelX = beginX;
    double pixelY = beginY;

    pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    deltaX /= pixels;
    deltaY /= pixels;

    while (pixels)
    {
        mlx_pixel_put(mlx, mlx_win, pixelX, beginY, color);
        mlx_pixel_put(mlx, mlx_win, pixelX, delta, color);
        mlx_pixel_put(mlx, mlx_win, beginX, pixelY, color);
        mlx_pixel_put(mlx, mlx_win, delta, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }

    return (pixels);
}

int draw_rectangle(void *mlx, void *mlx_win, int beginX, int beginY, int endX, int endY, int color)
{
    double  deltaX;
    double  deltaY;
    deltaX = endX - beginX;
    deltaY = endY - beginY;

    int pixels;
    pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    double  pixelX = beginX;
    double  pixelY = beginY;

    deltaX /= pixels;
    deltaY /= pixels;

    while (pixels)
    {
        mlx_pixel_put(mlx, mlx_win, pixelX, beginY, color);
        mlx_pixel_put(mlx, mlx_win, pixelX, endY, color);
        mlx_pixel_put(mlx, mlx_win, beginX, pixelY, color);
        mlx_pixel_put(mlx, mlx_win, endX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return (pixels);
}

int draw_fullbox(void *mlx, void *mlx_win, int beginX, int beginY, int endX, int endY, int color)
{
    double  deltaX;
    double  deltaY;
    deltaX = endX - beginX;
    deltaY = endY - beginY;

    int pixels;
    pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    double  pixelX = beginX;
    double  pixelY = beginY;

    deltaX /= pixels;
    deltaY /= pixels;

    while (pixels)
    {
        mlx_pixel_put(mlx, mlx_win, pixelX, beginY, color);
        mlx_pixel_put(mlx, mlx_win, pixelX, endY, color);
        mlx_pixel_put(mlx, mlx_win, beginX, pixelY, color);
        mlx_pixel_put(mlx, mlx_win, endX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }

    if (beginX < endX && beginY < endY)
        draw_fullbox(mlx, mlx_win, beginX + 1, beginY + 1, endX, endY, color);

    return (pixels);
}


int draw_circle(void *mlx, void *mlx_win, int x, int y, int radius, int color)
{   
    double  deltaX;
    double  deltaY;

    double  th = 3.14/180;
    deltaX = radius * cos(th) + x;
    deltaY = radius * sin(th) + y;

    int pixels;

    pixels = 360;

    double  pixelX = x - radius;
    double  pixelY = y + radius;

    while (pixels)
    {
        mlx_pixel_put(mlx, mlx_win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return (pixels);
}

int draw_test(void *mlx, void *mlx_win, int beginX, int beginY, int endX, int endY, int color)
{
    double  deltaX;
    double  deltaY;
    deltaX = endX - beginX;
    deltaY = endY - beginY;

    int pixels;
    pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    int half = pixels / 2;

    double  pixelX = beginX;
    double  pixelY = beginY;

    deltaX /= pixels;
    deltaY /= pixels;

    while (pixels)
    {
        mlx_pixel_put(mlx, mlx_win, pixelX, pixelY, color);
        pixelX += deltaX;
        if (pixels > half)
            pixelY += deltaY;
        else
            pixelY -= deltaY;
        --pixels;
    }

    return (pixels);

}

    // //draw line
    // draw_line(mlx, mlx_win, 1920, 0, 0, 0, 0xFFFFFF);

    // //draw box line
    // draw_box(mlx, mlx_win, 100, 100, 200, 0x00FF00);

    // //draw rectangle line
    // draw_rectangle(mlx, mlx_win, 250, 100, 400, 200, 0x0000FF);

    // //draw box full
    // draw_fullbox(mlx, mlx_win, 100, 300, 200, 400, 0x00FFFF);
    // draw_fullbox(mlx, mlx_win, 250, 300, 400, 400, 0xFFFF00);

    // // //draw sheet --- no success :(
    // // draw_trysheet(mlx, mlx_win, 1300, 100, 1700, 500, 25, 0xFFFF00);

    // //try triangle
    // draw_test(mlx, mlx_win, 1000, 200, 1500, 700, 0xFF00FF);

    // //draw circle
    // // draw_circle(mlx, mlx_win, 600, 600, 100, 0x00FF00);