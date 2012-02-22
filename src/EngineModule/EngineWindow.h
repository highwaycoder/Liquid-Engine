#ifndef __H_ENGINEWINDOW__
#define __H_ENGINEWINDOW__

#include <SFML/Window.hpp>

/* Forward declarations */
class CompositeRender;
class EngineEventHandler;
class KeyEvent;
class MouseEvent;

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

		float getFramerate() const;
		bool isOpen() const;

		void render() const;

		void onKeyPressed(KeyEvent&);
		void onKeyReleased(KeyEvent&);

		void onMouseMoved(MouseEvent&);
		void onMouseClicked(MouseEvent&);
		void onMouseReleased(MouseEvent&);
};

#endif

