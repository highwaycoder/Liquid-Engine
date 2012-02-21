#ifndef __H_ENGINEWINDOWEVENTDEFS__
#define __H_ENGINEWINDOWEVENTDEFS__

#include <stdint.h>

enum KeyCode
{
	A = 'a',
	B = 'b',
	C = 'c',
	D = 'd',
	E = 'e',
	F = 'f',
	G = 'g',
	H = 'h',
	I = 'i',
	J = 'j',
	K = 'k',
	L = 'l',
	M = 'm',
	N = 'n',
	O = 'o',
	P = 'p',
	Q = 'q',
	R = 'r',
	S = 's',
	T = 't',
	U = 'u',
	V = 'v',
	W = 'w',
	X = 'x',
	Y = 'y',
	Z = 'z',
	Num0 = '0',
	Num1 = '1',
	Num2 = '2',
	Num3 = '3',
	Num4 = '4',
	Num5 = '5',
	Num6 = '6',
	Num7 = '7',
	Num8 = '8',
	Num9 = '9', 
	EscapeKey = 256, //causes issues on windows if just "Escape"
	LControl,
	LShift,
	LAlt,
	LSystem,
	RControl,
	RShift,
	RAlt,
	RSystem,
	Menu,
	LBracket,
	RBracket,
	SemiColon,
	Comma,
	Period,
	Quote,
	Slash,
	BackSlash,
	Tilde,
	Equal,
	Dash,
	Space,
	Return,
	Back,
	Tab,
	PageUp,
	PageDown,
	End,
	Home,
	Insert,
	Delete,
	Add,
	Subtract,
	Multiply,
	Divide,
	Left,
	Right,
	Up,
	Down,
	Numpad0,
	Numpad1,
	Numpad2,
	Numpad3,
	Numpad4,
	Numpad5,
	Numpad6,
	Numpad7,
	Numpad8,
	Numpad9,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	F13,
	F14,
	F15,
	Pause
};

class Event
{

};

class MouseEvent : Event
{
	private:
		bool m_left;
		bool m_middle;
		bool m_right;
		int32_t m_x;
		int32_t m_y;

	public:
		MouseEvent(int32_t x, int32_t y, bool left, bool middle, bool right)
		{
			m_x = x;
			m_y = y;
			m_left = left;
			m_middle = middle;
			m_right = right;
		}

		bool isLeftButtonDown() const { return m_left; }
		bool isMiddleButtonDown() const { return m_middle; }
		bool isRightButtonDown() const { return m_right; }

		int32_t getX() const { return m_x; }
		int32_t getY() const { return m_y; }
};

class KeyEvent : Event
{
	private:
		uint16_t m_keycode;
		bool m_alt;
		bool m_shift;
		bool m_control;

	public:
		KeyEvent(uint16_t keycode, bool alt, bool shift, bool control)
		{
			m_keycode = keycode;
			m_alt = alt;
			m_shift = shift;
			m_control = control;
		}

		uint16_t getKeyCode() const { return m_keycode; }
		bool isAltPressed() const { return m_shift; }
		bool isShiftPressed() const { return m_alt; }
		bool isControlPressed() const { return m_control; }

};

#endif
