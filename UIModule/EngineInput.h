#ifndef __H_ENGINEINPUT__
#define __H_ENGINEINPUT__

#include "EngineKeyEvent.h"
#include "EngineMouseEvent.h"

class EngineInput
{

	public:
		EngineInput();

		virtual void OnKeyUp(EngineKeyEvent&) = 0;
		virtual void OnKeyDown(EngineKeyEvent&) = 0;

		virtual void OnMouseMove(EngineMouseEvent&) = 0;
		virtual void OnMousePress(EngineMouseEvent&) = 0;
		virtual void OnMouseRelease(EngineMouseEvent&) = 0;

};

#endif
