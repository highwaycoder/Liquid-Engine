#include "EngineKeyEvent.h"

EngineKeyEvent::EngineKeyEvent(int32_t key_code, bool shift, bool alt, bool control)
{
	m_key_code = key_code;

	m_shift = shift;
	m_alt = alt;
	m_control = control;
}
