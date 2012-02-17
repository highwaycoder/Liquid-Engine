#ifndef __H_WINDOWTHREAD__
#define __H_WINDOWTHREAD__

#include <SFML/System.hpp>

#include "EngineWindow.h"

/* Forward declaration needed so that we can reference window from thread */
class EngineWindow;

class EngineWindowThread : public sf::Thread
{
	private:
		EngineWindow* m_window;

		virtual void Run();

	public:
		EngineWindowThread(EngineWindow*);
};

#endif
