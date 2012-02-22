#include "EngineWindow.h"

#include "EngineWindowEventDefs.h"
#include "EngineEventHandler.h"
#include "RenderModule/CompositeRender.h"

EngineWindow::EngineWindow()
{
	m_window = new sf::Window(sf::VideoMode(800, 600, 32), "SFML Events");
	m_render = new CompositeRender();
}

EngineWindow::~EngineWindow()
{

}

float EngineWindow::getFramerate() const
{
	return (1.0f / m_window->GetFrameTime());
}

bool EngineWindow::isOpen() const
{
	return m_window->IsOpened();
}

void EngineWindow::render() const
{
	m_render->Render();
}

void EngineWindow::onKeyPressed(KeyEvent& event)
{
	if (m_event_handler != NULL)
	{
		m_event_handler->onKeyPressed(event);
	}
}

void EngineWindow::onKeyReleased(KeyEvent& event)
{
	if (m_event_handler != NULL)
	{
		m_event_handler->onKeyReleased(event);
	}
}

void EngineWindow::onMouseMoved(MouseEvent& event)
{
	if (m_event_handler != NULL)
	{
		m_event_handler->onMouseMoved(event);
	}
}

void EngineWindow::onMouseClicked(MouseEvent& event)
{
	if (m_event_handler != NULL)
	{
		m_event_handler->onMouseClicked(event);
	}
}

void EngineWindow::onMouseReleased(MouseEvent& event)
{
	if (m_event_handler != NULL)
	{
		m_event_handler->onMouseReleased(event);
	}
}
