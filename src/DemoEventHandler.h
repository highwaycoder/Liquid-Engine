#ifndef __H_DEMOEVENTHANDLER__
#define __H_DEMOEVENTHANDLER__

#include "EngineModule/EngineEventHandler.h"

class DemoEventHandler : public EngineEventHandler
{
	public:
		virtual void onKeyPressed(KeyEvent&);
		virtual void onKeyReleased(KeyEvent&);

		virtual void onMouseMoved(MouseEvent&);
		virtual void onMouseClicked(MouseEvent&);
		virtual void onMouseReleased(MouseEvent&);
};

#endif
