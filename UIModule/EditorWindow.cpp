#include "EditorWindow.h"


EditorWindow::EditorWindow() : wxFrame(NULL, wxID_ANY, wxT("Liquid Engine - Editor Window"), wxDefaultPosition, wxSize(800, 600))
{
	EngineCanvas* canvas = new EngineCanvas(this);
	Centre();
}

