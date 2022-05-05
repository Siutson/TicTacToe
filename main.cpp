#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void close();
void fillScreenSurfrace();

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

int main( int argc, char* args[] )
{

    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    else
    {
        //create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Can't create window! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            fillScreenSurfrace();
            SDL_Delay(2000); //delay to make window visible before program closes

        }
    }
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