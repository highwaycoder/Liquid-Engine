#include "EngineWindow.h"

#include "EngineWindowEventDefs.h"

EngineWindow::EngineWindow()
{
	m_window = new sf::Window(sf::VideoMode(800, 600, 32), "SFML Events");
	m_render = new CompositeRender();
}

EngineWindow::~EngineWindow()
{

}

bool EngineWindow::isOpen() const
{
	return m_window->IsOpened();
}

void EngineWindow::render() const
{
	m_render->Render();
}
