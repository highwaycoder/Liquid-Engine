#ifndef __H_ENGINEWINDOWMANAGER__
#define __H_ENGINEWINDOWMANAGER__

#include <list>

#include "EngineWindow.h"

/* Forward declarations */
class EngineApplication;
class KeyEvent;
class MouseEvent;

class EngineWindowManager
{
	friend class EngineApplication;

	private:
		std::list<EngineWindow*> m_windows;

	public:
		EngineWindowManager();
		~EngineWindowManager();

		EngineWindow* createWindow();

		void dispatchEvents();
		void renderFrames();	

		void onWindowPaint(EngineWindow* window);
		void onWindowClose(EngineWindow* window);

		void onKeyPressed(EngineWindow* window, KeyEvent&);
		void onKeyReleased(EngineWindow* window, KeyEvent&);

		void onMouseMoved(EngineWindow* window, MouseEvent&);
		void onMouseClicked(EngineWindow* window, MouseEvent&);
		void onMouseReleased(EngineWindow* window, MouseEvent&);
};

#endif
