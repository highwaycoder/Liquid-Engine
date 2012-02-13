#include "EngineCanvas.h"

BEGIN_EVENT_TABLE(EngineCanvas, wxGLCanvas)
	EVT_PAINT	(EngineCanvas::Paintit)
END_EVENT_TABLE()

EngineCanvas::EngineCanvas(wxFrame *parent) : wxGLCanvas(parent, wxID_ANY,  wxDefaultPosition, wxDefaultSize, 0, wxT("GLCanvas"))
{

}
 
void EngineCanvas::Paintit(wxPaintEvent& WXUNUSED(event))
{
	Render();
}
 
void EngineCanvas::Render()
{
    SetCurrent();
    wxPaintDC(this);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);
 
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glColor3f(0.4, 0.5, 0.4);
        glVertex2f(0.0, -0.8);
    glEnd();
 
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.1, 0.1);
        glVertex2f(-0.1, 0.1);
        glVertex2f(-0.1, -0.1);
        glVertex2f(0.1, -0.1);
    glEnd();
  
    glFlush();
    SwapBuffers();
}

 
 

  

