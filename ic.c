#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
int main()
{
    printf("Helo World \n");
    FILE *in = stdin;

    char *pthroway = calloc(1000, sizeof(char));
    fgets(pthroway, 1000, in);
    //  fgets(pthroway, 1000, in);
    // fgets(pthroway, 1000, in);
    // fgets(pthroway, 1000, in);

    char *pdimensions = calloc(1000, sizeof(char));
    fgets(pdimensions, 1000, in);

    int width = -1, height = -1;
    sscanf(pdimensions, "%d %d\n", &width, &height);
    printf("width = %d height = %d\n", width, height);

    /*
    SDL_Window * SDL_CreateWindow(const char *title,
                              int x, int y, int w,
                              int h, Uint32 flags);
    */
    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                           width, height, 0);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    Uint8 r=0, g=0, b=0;
    Uint32 color = SDL_MapRGB(psurface->format, r, g, b);
    SDL_Rect pixel = (SDL_Rect){0, 0, 1, 1};
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            r = (char)getchar();
            g = (char)getchar();
            b = (char)getchar();
            // fread(&r, 1, 1, stdin);
            // fread(&g, 1, 1, stdin);
            // fread(&b, 1, 1, stdin);
            color = SDL_MapRGB(psurface->format, r, g, b);
            pixel.x = x;
            pixel.y = y;
            SDL_FillRect(psurface, &pixel, color);
        }
    }
    SDL_UpdateWindowSurface(pwindow);
    int app_running = 1;
    SDL_Event event;
    while (app_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                app_running = 0;
                // return 0;
            }
            SDL_Delay(20);
        }
    }
    // SDL_Event e;
    // while (1)
    // {
    //     while (SDL_PollEvent(&e))
    //     {
    //         if (e.type == SDL_QUIT)
    //             return 0;
    //     }
    //     SDL_Delay(20);
    // }
}