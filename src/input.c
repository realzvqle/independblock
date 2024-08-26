#include "input.h"
#include <winuser.h>




extern bool KEYS[322];





void handle_input(){
    if(KEYS[SDLK_w]){
        MessageBoxA(NULL, "h", NULL, MB_OK);
    }
}