#ifndef __H_ENGINEWINDOW__
#define __H_ENGINEWINDOW__

#include <wx/wx.h>

class EngineWindow : public wxFrame
{
	private:
		void OnKeyDown(wxKeyEvent&);
		void OnKeyUp(wxKeyEvent&);
		void OnMouseEvent(wxMouseEvent&);

	public:
		EngineWindow();

		/* This is probably the only scenario where I will ever think this is a good idea */
		friend class EngineCanvas;

		//DECLARE_EVENT_TABLE()
};

#endif
