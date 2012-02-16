#include "EngineMouseEvent.h"

EngineMouseEvent::EngineMouseEvent(int32_t x, int32_t y, bool left_button_pressed, bool middle_button_pressed, bool right_button_pressed)
{
	m_x = x;
	m_y = y;

	m_left_button_pressed = left_button_pressed;
	m_middle_button_pressed = middle_button_pressed;
	m_right_button_pressed = right_button_pressed;

}

