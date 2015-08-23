#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_EVERYTHING);      // Įjungiam SDL
    atexit(SDL_Quit);                   //Įsitikinam, kad SDL išsivalys prie išjungimą

    // Sukuriam naują langą
    SDL_Surface* langas = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("Žemėlapio žymėjimo programa", NULL);

    bool done = false;
    while (!done)                       //Programos pagrindinis ciklas
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))   //Žinučių apdorojimo ciklas
        {
            switch (event.type)         //Patikrinam ar yra žinučių
            {
            case SDL_QUIT:              //Išjungimas
                done = true;
                break;

            case SDL_KEYDOWN:           //Mygtukų paspaudimai
                {
                    // Jei paspaudžiam ESC išjungiama programa
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            case SDL_VIDEORESIZE:       //Keičiam lango dydį
                    langas = SDL_SetVideoMode(event.resize.w, event.resize.h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                    break;
            }
        }

        /// Prasideda piešimas

        // Išvalom ekraną
        SDL_FillRect(langas, 0, SDL_MapRGB(langas->format, 255, 255, 255));

        /// Pasibaigia piešimas

        // Atnaujinam ekraną
        SDL_Flip(langas);
    }
    printf("Programa baigė darbą tvarkingai.");
    return 0;
}
