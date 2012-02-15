#ifndef __ENGINECANVAS_H__
#define __ENGINECANVAS_H__

#include "wx/wx.h"
#include "wx/glcanvas.h"
#include "wx/window.h"

#include "RenderModule/CompositeRender.h"

class EngineCanvas : public wxGLCanvas
{
        void Render();

	public:
		EngineCanvas(wxFrame* parent);

		EngineCanvas(wxWindow* parent);


		void Paintit(wxPaintEvent& event);
	protected:
		DECLARE_EVENT_TABLE()

	private:
		CompositeRender render;
};

#endif

