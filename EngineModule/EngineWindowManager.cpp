#include "EngineWindowManager.h"

#include <list>
#include <stdio.h>
#include "EngineWindow.h"
#include "EngineWindowEventDefs.h"

EngineWindowManager::EngineWindowManager()
{

}

EngineWindowManager::~EngineWindowManager()
{

}

EngineWindow* EngineWindowManager::createWindow()
{
	EngineWindow* window = new EngineWindow();

	m_windows.push_back(window);

	return window;
}

void EngineWindowManager::processWindows()
{
	EngineWindow* window;
	std::list<EngineWindow*>::iterator iter;
	sf::Event sfml_event;
	sf::Window* sfml_window;

	for (iter = m_windows.begin(); iter != m_windows.end(); iter++)
	{
		
		window = *iter;

		if (window->isOpen())
		{
			sfml_window = window->getSFMLWindow();

			/* Process events */
			while (sfml_window->GetEvent(sfml_event))
			{
				/* Close the window */
				if (sfml_event.Type == sf::Event::Closed)
				{
					onWindowClose(window);
					return; /* Go no further */
				}

			}

			/* Paint it */
			onWindowPaint(window);
		}
		else
		{
			/* Free the window from the manager */
			onWindowClose(window);
		}
	}
}

void EngineWindowManager::onWindowClose(EngineWindow* window)
{
	printf("closed that fucker.\n");
	m_windows.remove(window);

	/* Tell SFML to close the window */
	window->getSFMLWindow()->Close();
}

void EngineWindowManager::onWindowPaint(EngineWindow* window)
{
	printf("paint that cunt.\n");

	/* Activate the SFML OpenGL drawing context */
	window->getSFMLWindow()->SetActive();

	/* Draw */
	window->render();

	/* Tell SFML to display it */
	window->getSFMLWindow()->Display();
}

void EngineWindowManager::onKeyPressed(EngineWindow* window, KeyEvent& event)
{
	
}

void EngineWindowManager::onKeyReleased(EngineWindow* window, KeyEvent& event)
{
	
}

void EngineWindowManager::onMouseMoved(EngineWindow* window, MouseEvent& event)
{
	
}

void EngineWindowManager::onMouseClicked(EngineWindow* window, MouseEvent& event)
{
	
}
