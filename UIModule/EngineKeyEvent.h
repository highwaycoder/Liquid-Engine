#ifndef __H_ENGINEKEYEVENT__
#define __H_ENGINEKEYEVENT__

#include "EngineEvent.h"

#include <stdint.h>

class EngineKeyEvent : EngineEvent
{
	private:
		bool m_shift;
		bool m_alt;
		bool m_control;
		uint32_t m_key_code;

	public:
		EngineKeyEvent(int32_t, bool, bool, bool);

		int32_t getKeyCode() const { return m_key_code; }

		bool isShiftPressed() const { return m_shift; }
		bool isAltPressed() const { return m_alt; }
		bool isControlPressed() const { return m_control; }
};


#endif
