#ifndef __UIAPP_H__
#define __UIAPP_H__


#include "wx/wx.h"
#include "wx/glcanvas.h"

#include "EditorWindow.h"
#include "EngineWindow.h"

class UIApp : public wxApp
{
	virtual bool OnInit();
	wxGLCanvas* MyGLCanvas;
};

#endif
