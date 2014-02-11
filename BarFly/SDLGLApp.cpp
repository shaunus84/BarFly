//
//  SDLGLApp.cpp
//  BarFly
//
//  Created by Shaun Mitchell on 11/02/2014.
//  Copyright (c) 2014 Culprit Games. All rights reserved.
//

#include "SDLGLApp.h"

SDLGLApp::SDLGLApp() :  m_pSDLWindow(0),
m_pMainContext(0)
{
    
}

SDLGLApp::~SDLGLApp()
{
}


bool SDLGLApp::initSDL(int width, int height)
{
    bool success = false;
    if(SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        std::cout << "SDL Init success\n";
        
        m_pSDLWindow = SDL_CreateWindow("BarFly", 0, 0, width, height, SDL_WINDOW_OPENGL);
        
        if(m_pSDLWindow != NULL)
        {
            std::cout << "SDL window and renderer created";
            
            success = true;
            
            m_bRunning = true;
        }
    }
    return success;
}

bool SDLGLApp::initGL()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    
    SDL_GL_CreateContext(m_pSDLWindow);
    return true;
}

void SDLGLApp::update()
{
    
}

void SDLGLApp::render()
{
    /* Set the background black */
    glClearColor( 1.0f, 0.0f, 0.0f, 0.0f );
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    /* Move Left 1.5 Units And Into The Screen 6.0 */
    glLoadIdentity();
    glTranslatef( 0.0f, 0.0f, -6.0f );
    
    glBegin( GL_TRIANGLES );            /* Drawing Using Triangles */
    glVertex3f(  0.0f,  1.0f, 0.0f ); /* Top */
    glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
    glVertex3f(  1.0f, -1.0f, 0.0f ); /* Bottom Right */
    glEnd( );                           /* Finished Drawing The Triangle */
    
    /* Move Right 3 Units */
    glTranslatef( 3.0f, 0.0f, 0.0f );
    
    glBegin( GL_QUADS );                /* Draw A Quad */
    glVertex3f( -1.0f,  1.0f, 0.0f ); /* Top Left */
    glVertex3f(  1.0f,  1.0f, 0.0f ); /* Top Right */
    glVertex3f(  1.0f, -1.0f, 0.0f ); /* Bottom Right */
    glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
    glEnd( );                           /* Done Drawing The Quad */
}
