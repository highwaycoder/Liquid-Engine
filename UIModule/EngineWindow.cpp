#include "EngineWindow.h"

#include "EngineCanvas.h"

EngineWindow::EngineWindow() : wxFrame(NULL, wxID_ANY, wxT("Liquid Engine - Engine Window"), wxDefaultPosition, wxSize(800, 600))
{
	new EngineCanvas(this);

	Centre();
}

