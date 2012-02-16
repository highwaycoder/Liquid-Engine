#ifndef __H_ENGINEMOUSEEVENT__
#define __H_ENGINEMOUSEEVENT__

#include "EngineEvent.h"

#include <stdint.h>

class EngineMouseEvent : EngineEvent
{
	private:
		bool m_left_button_pressed;
		bool m_middle_button_pressed;
		bool m_right_button_pressed;

		int32_t m_x;
		int32_t m_y;

	public:
		EngineMouseEvent(int32_t, int32_t, bool, bool, bool);

		int32_t getX() const { return m_x; }
		int32_t getY() const { return m_y; }

		bool isLeftPressed() const { return m_left_button_pressed; }
		bool isMiddlePressed() const { return m_middle_button_pressed; }
		bool isRightPressed() const { return m_right_button_pressed; }
};


#endif
