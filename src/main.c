#include "externincludes/SDL2/SDL_video.h"
#include "independblock.h"
#include "cube.h"



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
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("OpenGL Fun!",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          1920, 1080,
                                          SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Failed to create SDL Window: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        printf("Failed to create SDL + OpenGL 1 Context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Failed to Load GLAD\n");
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    glViewport(0, 0, 1920, 1080);
    setupPerspective(45.0f, 1920.0f / 1080.0f, 0.1f, 100.0f);
    float angle = 0.0f;

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);

        draw_cube(1, (vector3){0.5, 0.5, 0.5}, (vector3){0.5, 3, 0.5});
        draw_cube(1, (vector3){0.6, 0.5, 0.5}, (vector3){0, 9, 4});
        draw_cube(2, (vector3){1, 0.3, 0.2}, (vector3){7, 9, 4});


        SDL_GL_SwapWindow(window);
        angle += 0.5f;
    }
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
