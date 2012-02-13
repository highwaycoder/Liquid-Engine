#ifndef __ENGINECANVAS_H__
#define __ENGINECANVAS_H__

#include "wx/wx.h"
#include "wx/glcanvas.h"

class EngineCanvas : public wxGLCanvas
{
        void Render();

	public:
		EngineCanvas(wxFrame* parent);
		void Paintit(wxPaintEvent& event);
	protected:
		DECLARE_EVENT_TABLE()
};

#endif

