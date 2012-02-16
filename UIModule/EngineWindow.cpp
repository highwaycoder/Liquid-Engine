#include "EngineWindow.h"

#include "EngineCanvas.h"

#include <stdio.h>


EngineWindow::EngineWindow() : wxFrame(NULL, wxID_ANY, wxT("Liquid Engine - Engine Window"), wxDefaultPosition, wxSize(800, 600))
{
	new EngineCanvas(this);

	Centre();
}


void EngineWindow::OnKeyDown(wxKeyEvent& event)
{
	if (m_registered_input != NULL)
	{
		EngineKeyEvent engine_event(event.GetKeyCode(), event.ShiftDown(), event.AltDown(), event.ControlDown());
		m_registered_input->OnKeyDown(engine_event);
	}
}

void EngineWindow::OnKeyUp(wxKeyEvent& event)
{
	if (m_registered_input != NULL)
	{
		EngineKeyEvent engine_event(event.GetKeyCode(), event.ShiftDown(), event.AltDown(), event.ControlDown());
		m_registered_input->OnKeyUp(engine_event);
	}
}

void EngineWindow::OnMouseEvent(wxMouseEvent& event)
{
	if (m_registered_input != NULL)
	{
		if (event.Moving())
		{
			EngineMouseEvent mouse_event(event.GetX(), event.GetY(), event.LeftDown(), event.MiddleDown(), event.RightDown());
			m_registered_input->OnMouseMove(mouse_event);
		}
		else if (event.ButtonDown())
		{
			EngineMouseEvent mouse_event(event.GetX(), event.GetY(), event.LeftDown(), event.MiddleDown(), event.RightDown());
			m_registered_input->OnMousePress(mouse_event);
		}
		else if (event.ButtonUp())
		{
			EngineMouseEvent mouse_event(event.GetX(), event.GetY(), event.LeftDown(), event.MiddleDown(), event.RightDown());
			m_registered_input->OnMouseRelease(mouse_event);
		}
	}
}

