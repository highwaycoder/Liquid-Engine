#include "UIApp.h"

IMPLEMENT_APP_NO_MAIN(UIApp)

bool UIApp::OnInit()
{
    wxFrame *frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello GL World"), wxPoint(50,50), wxSize(200,200));
    new EngineCanvas(frame);

    frame->Show(TRUE);
    return TRUE;
}

