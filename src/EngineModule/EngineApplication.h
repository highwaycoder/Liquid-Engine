#ifndef __H_ENGINEAPPLICATION__
#define __H_ENGINEAPPLICATION__

#include "EngineWindowManager.h"

class EngineApplication
{
	private:
		EngineWindowManager* m_windowmanager;

	public:
		EngineApplication();

		void run();

		EngineWindowManager& getWindowManager() { return *m_windowmanager; }
};

#endif
