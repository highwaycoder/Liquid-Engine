#include "UIApp.h"

IMPLEMENT_APP_NO_MAIN(UIApp)

bool UIApp::OnInit()
{
	EditorWindow* editor = new EditorWindow(); 
	EngineWindow* engine = new EngineWindow();

	editor->Show(TRUE);
	engine->Show(TRUE);

	return TRUE;
}

