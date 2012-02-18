#ifndef __H_ENGINEWINDOW__
#define __H_ENGINEWINDOW__

#include <SFML/Window.hpp>

#include "RenderModule/CompositeRender.h"

#include "EngineEventHandler.h"

class EngineWindow
{
	friend class EngineWindowManager;

	private:
		sf::Window* m_window;
		CompositeRender* m_render;
		EngineEventHandler* m_event_handler;


	public:
		EngineWindow();
		~EngineWindow();

		void registerEventHandler(EngineEventHandler* value) { m_event_handler = value; }
		void unregisterEventHandler() { m_event_handler = NULL; }


		sf::Window* getSFMLWindow() { return m_window; }

		bool isOpen() const;

		void render() const;
};

#endif

