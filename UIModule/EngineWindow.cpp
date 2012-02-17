#include "EngineWindow.h"

EngineWindow::EngineWindow()
{
	m_window = new sf::Window(sf::VideoMode(800, 600, 32), "SFML Events");
	m_thread = new EngineWindowThread(this);

	m_thread->Launch();
}

EngineWindow::~EngineWindow()
{

}
