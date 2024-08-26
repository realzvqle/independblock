#include "externincludes/SDL2/SDL_video.h"
#include "independblock.h"
#include "cube.h"
#include "input.h"
#include <winuser.h>

#define WINDOWX 1600
#define WINDOWY 900




bool KEYS[322];


void setupPerspective(float fovY, float aspect, float near, float far) {
    float top = near * tanf(fovY * 0.5f * 3.14159265358979323846f / 180.0f);
    float right = top * aspect;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-right, right, -top, top, near, far);
    glMatrixMode(GL_MODELVIEW);
}




int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOALIGNMENTFAULTEXCEPT | SEM_NOGPFAULTERRORBOX);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        MessageBoxW(NULL, L"Failed to initialize SDL",L"Independblock Engine Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("IndependBlock",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOWX, WINDOWY,
                                          SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        MessageBoxW(NULL, L"Failed to create window",L"Independblock Engine Error", MB_OK | MB_ICONERROR);
        SDL_Quit();
        return -1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        MessageBoxW(NULL, L"Failed to create OpenGL context",L"Independblock Engine Error", MB_OK | MB_ICONERROR);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        MessageBoxW(NULL, L"Failed to load GLAD",L"Independblock Engine Error", MB_OK | MB_ICONERROR);
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    glViewport(0, 0, WINDOWX, WINDOWY);
    setupPerspective(75.0f, 1600.0f / 900.0f, 0.1f, 100.0f);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    KEYS[event.key.keysym.sym] = true;
                    break;
                case SDL_KEYUP:
                    KEYS[event.key.keysym.sym] = false;
                    break;
                default:
                    break;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(-2.0f, 0.0f, -5.0f);
        handle_input();

        for(float i = 0; i < 12; i++){
            for(float j = 0; j < 12; j++){
                draw_cube(0.5, (vector3){i / 3, -1, j / 3}, (vector3){0, 0, 0}, false);
            }
        }
        
        SDL_GL_SwapWindow(window);
    }
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
