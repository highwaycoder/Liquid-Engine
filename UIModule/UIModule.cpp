#include "UIModule.h"

#include "stdio.h"

#include "wx/wx.h"

#include "UIApp.h"
#include "EngineCanvas.h"

void startUIModule()
{
	int argc = 0;
	char** argv = NULL;

	UIApp* application = new UIApp;

	UIApp::SetInstance(application);

	wxEntry(argc, argv);

}

void closeUIModule()
{
	wxEntryCleanup();
}
