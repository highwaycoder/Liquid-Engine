#include "EngineWindowThread.h"

#include <stdio.h>

EngineWindowThread::EngineWindowThread(EngineWindow* window)
{
	m_window = window;
}

void EngineWindowThread::Run()
{
	while (m_window->getWindow()->IsOpened())
	{
		sf::Event Event;

		while (m_window->getWindow()->GetEvent(Event))
		{
			if (Event.Type == sf::Event::Closed)
			{
				m_window->getWindow()->Close();
			}
		}

		printf("fuck\n");
	}
}
