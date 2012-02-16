#ifndef __ENGINECANVAS_H__
#define __ENGINECANVAS_H__

#include "wx/wx.h"
#include "wx/glcanvas.h"
#include "wx/window.h"

#include "RenderModule/CompositeRender.h"

#include "EngineWindow.h"

class EngineCanvas : public wxGLCanvas
{
	public:
		EngineCanvas(EngineWindow*);

		void OnKeyDown(wxKeyEvent& event);
		void OnKeyUp(wxKeyEvent& event);
		void OnMouseEvent(wxMouseEvent& event);

		void Paintit(wxPaintEvent& event);

    		void Render();

	protected:
		EngineWindow* m_parent_window;

		DECLARE_EVENT_TABLE()

	private:
		CompositeRender render;
};

#endif

