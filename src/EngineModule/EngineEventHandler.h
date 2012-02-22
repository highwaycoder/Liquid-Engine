#ifndef __H_ENGINEEVENTHANDLER__
#define __H_ENGINEEVENTHANDLER__

#include "EngineWindowEventDefs.h"

class EngineEventHandler
{
	public:
		virtual void onKeyPressed(KeyEvent&) = 0;
		virtual void onKeyReleased(KeyEvent&) = 0;

		virtual void onMouseMoved(MouseEvent&) = 0;
		virtual void onMouseClicked(MouseEvent&) = 0;
		virtual void onMouseReleased(MouseEvent&) = 0;
};

#endif
