#ifndef __H_ENGINEWINDOW__
#define __H_ENGINEWINDOW__

#include <SFML/Window.hpp>

/* Forward declarations */
class CompositeRender;
class EngineEventHandler;


class EngineWindow
{
	friend class EngineWindowManager;

	private:
		EngineWindow();

		sf::Window* m_window;
		CompositeRender* m_render;
		EngineEventHandler* m_event_handler;

	public:
		~EngineWindow();

		void registerEventHandler(EngineEventHandler* value) { m_event_handler = value; }
		void unregisterEventHandler() { m_event_handler = NULL; }


		sf::Window* getSFMLWindow() { return m_window; }

		bool isOpen() const;

		void render() const;
};

#endif
