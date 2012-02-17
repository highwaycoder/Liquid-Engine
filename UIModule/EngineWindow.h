#ifndef __H_ENGINEWINDOW__
#define __H_ENGINEWINDOW__

#include <SFML/Window.hpp>

#include "EngineWindowThread.h"

/* Forward declaration needed so that we can reference thread from window */
class EngineWindowThread;

class EngineWindow
{
	private:
		sf::Window* m_window;
		EngineWindowThread* m_thread;

	public:
		EngineWindow();
		~EngineWindow();

		sf::Window* getWindow() { return m_window; }
};

#endif
