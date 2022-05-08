#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#define IMG_PATH "images/iks.png"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void close();
void fillScreenSurfrace();

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

int main( int argc, char* args[] )
{
    SDL_Renderer *renderer = NULL;
    SDL_Texture *img = NULL;
    int w, h;

    //initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    //create window
    window = SDL_CreateWindow( "TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        printf( "Can't create window! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //create accelerated renderer

    img = IMG_LoadTexture(renderer, IMG_PATH);
    SDL_QueryTexture(img, NULL, NULL, &w, &h); //get width and height from image
    SDL_Rect texr; texr.x = SCREEN_WIDTH/2; texr.y = SCREEN_HEIGHT/2; texr.w = w; texr.h = h;

    while(1){
        SDL_Event e;
        if ( SDL_PollEvent(&e) ) {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
        } 
        
        // clear the screen
        SDL_RenderClear(renderer);
        fillScreenSurfrace();
        // copy the texture to the rendering context
        SDL_RenderCopy(renderer, img, NULL, &texr);
        // printf("Err message from img renderer: %s\n", SDL_GetError());
        // flip the backbuffer
        // this means that everything that we prepared behind the screens is actually shown
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(renderer);
    close();

    return 0;
}


void close(){
    
    SDL_DestroyWindow(window); //destroy window
    SDL_Quit(); //quit SDL subsystems
}

void fillScreenSurfrace(){
    screenSurface = SDL_GetWindowSurface( window ); //get window surface
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 255, 255)); //fill surface with color
    SDL_UpdateWindowSurface(window); //update color changes
}