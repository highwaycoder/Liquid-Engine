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
	if (event.GetKeyCode() == 309)
		printf("hello\n");

	printf("Character %c num: %i\n", (char)event.GetKeyCode(), event.GetKeyCode());
}

void EngineWindow::OnKeyUp(wxKeyEvent& event)
{

}

void EngineWindow::OnMouseEvent(wxMouseEvent& event)
{

}

