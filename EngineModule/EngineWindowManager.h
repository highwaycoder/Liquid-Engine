#ifndef __H_ENGINEWINDOWMANAGER__
#define __H_ENGINEWINDOWMANAGER__

#include <list>
#include <stdint.h>
#include <stdio.h>

#include "EngineWindow.h"

#include "EngineWindowEventDefs.h"

class EngineWindow;

class EngineWindowManager
{

	private:
		std::list<EngineWindow*> m_windows;

	public:
		EngineWindowManager();
		~EngineWindowManager();

		EngineWindow* createWindow();

		void processWindows();
	
		void onWindowPaint(EngineWindow* window);
		void onWindowClose(EngineWindow* window);

		void onKeyPressed(EngineWindow* window, KeyEvent&);
		void onKeyReleased(EngineWindow* window, KeyEvent&);

		void onMouseMoved(EngineWindow* window, MouseEvent&);
		void onMouseClicked(EngineWindow* window, MouseEvent&);

};

#endif
