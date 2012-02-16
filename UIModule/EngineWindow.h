#ifndef __H_ENGINEWINDOW__
#define __H_ENGINEWINDOW__

#include <wx/wx.h>

#include "EngineInput.h"

class EngineWindow : public wxFrame
{
	private:
		void OnKeyDown(wxKeyEvent&);
		void OnKeyUp(wxKeyEvent&);
		void OnMouseEvent(wxMouseEvent&);

		EngineInput* m_registered_input; /* The referenced input class will recieve events from this window */

	public:
		EngineWindow();

		void registerInput(EngineInput& value) { m_registered_input = &value; }
		void unregisterInput() { m_registered_input = NULL; }

		/* This is probably the only scenario where I will ever think this is a good idea */
		friend class EngineCanvas;

		//DECLARE_EVENT_TABLE()
};

#endif
