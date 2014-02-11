//
//  main.cpp
//  BarFly
//
//  Created by Shaun Mitchell on 11/02/2014.
//  Copyright (c) 2014 Culprit Games. All rights reserved.
//

#include <iostream>
#include "SDLGLApp.h"

SDLGLApp* g_pSDLGLApp;

int main()
{
    g_pSDLGLApp = new SDLGLApp();
    
    if(!g_pSDLGLApp->initSDL(500, 500))
    {
        return -1;
    }
    
    if(!g_pSDLGLApp->initGL())
    {
        return -1;
    }
    
    while (g_pSDLGLApp->isRunning())
    {
        g_pSDLGLApp->render();
    }
    
    return 0;
}
