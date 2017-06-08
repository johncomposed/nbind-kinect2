#include <iostream>
#include <libfreenect2/libfreenect2.hpp>
#include <SDL2/SDL.h>
#include <unistd.h>

#include "Kontext.h"

Kontext* kontext;

libfreenect2::Freenect2 api;
libfreenect2::Freenect2Device* device;

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow(
                "Kinect Viewer",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                1920,
                1080,
                SDL_WINDOW_MAXIMIZED | SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event* event;
    SDL_Rect origin;
    origin.x = 0;
    origin.y = 0;
    origin.w = 1920;
    origin.h = 1080;

    kontext = new Kontext();
    kontext->openDevice();

    while(1){
        SDL_PollEvent(event);
        if(event->type == SDL_QUIT){
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        // get frame
        uint8_t* fdata = kontext->getFrame();
        if(fdata != nullptr) {
            SDL_Surface *surf = SDL_CreateRGBSurfaceWithFormatFrom(fdata, 1920,
                                                                   1080, 32,
                                                                   4 * 1920,
                                                                   SDL_PIXELFORMAT_RGBX8888);
            SDL_Texture *sframe = SDL_CreateTextureFromSurface(renderer, surf);


            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, sframe, NULL, &origin);
            SDL_RenderPresent(renderer);

            SDL_FreeSurface(surf);
            SDL_DestroyTexture(sframe);
        } else {
            printf("NO FRAME DATA");
        }
        delete [] fdata;
        fdata = NULL;
    }

    delete kontext;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
