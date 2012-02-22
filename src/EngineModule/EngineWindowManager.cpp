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

void EngineWindowManager::dispatchEvents()
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

				/* Key is Pressed */
				if (sfml_event.Type == sf::Event::KeyPressed)
				{
					KeyEvent event(sfml_event.Key.Code, sfml_event.Key.Alt, sfml_event.Key.Shift, sfml_event.Key.Control);
					
					/* Feed the event down the pipeline */
					onKeyPressed(window, event);
				}

				/* Key is Released */
				if (sfml_event.Type == sf::Event::KeyReleased)
				{
					KeyEvent event(sfml_event.Key.Code, sfml_event.Key.Alt, sfml_event.Key.Shift, sfml_event.Key.Control);
					
					/* Feed the event down the pipeline */
					onKeyReleased(window, event);
				}

				/* Mouse Moved */
				if (sfml_event.Type == sf::Event::MouseMoved)
				{
					MouseEvent event(sfml_event.MouseMove.X, sfml_event.MouseMove.Y, false, false, false);

					/* Feed the event down the pipeline */
					onMouseMoved(window, event);
				}

				/* Mouse Clicked */
				if (sfml_event.Type == sf::Event::MouseButtonPressed)
				{
					bool left_button = (sfml_event.MouseButton.Button == 0);
					bool middle_button = sfml_event.MouseButton.Button & 2;
					bool right_button = sfml_event.MouseButton.Button & 1;

					MouseEvent event(sfml_event.MouseButton.X, sfml_event.MouseButton.Y, left_button, middle_button, right_button);

					/* Feed the event down the pipeline */
					onMouseClicked(window, event);
				}

				/* Mouse Released */
				if (sfml_event.Type == sf::Event::MouseButtonReleased)
				{
					bool left_button = (sfml_event.MouseButton.Button == 0);
					bool middle_button = sfml_event.MouseButton.Button & 2;
					bool right_button = sfml_event.MouseButton.Button & 1;

					MouseEvent event(sfml_event.MouseButton.X, sfml_event.MouseButton.Y, left_button, middle_button, right_button);

					/* Feed the event down the pipeline */
					onMouseReleased(window, event);
				}
			}
		}
		else
		{
			/* Free the window from the manager */
			onWindowClose(window);
		}
	}
}

void EngineWindowManager::renderFrames()
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
			/* Paint it */
			onWindowPaint(window);
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
	/* Activate the SFML OpenGL drawing context */
	window->getSFMLWindow()->SetActive();

	/* Draw */
	window->render();

	/* Tell SFML to display it */
	window->getSFMLWindow()->Display();
}

void EngineWindowManager::onKeyPressed(EngineWindow* window, KeyEvent& event)
{
	window->onKeyPressed(event);
}

void EngineWindowManager::onKeyReleased(EngineWindow* window, KeyEvent& event)
{
	window->onKeyReleased(event);
}

void EngineWindowManager::onMouseMoved(EngineWindow* window, MouseEvent& event)
{
	window->onMouseMoved(event);
}

void EngineWindowManager::onMouseClicked(EngineWindow* window, MouseEvent& event)
{
	window->onMouseClicked(event);
}

void EngineWindowManager::onMouseReleased(EngineWindow* window, MouseEvent& event)
{
	window->onMouseReleased(event);
}
