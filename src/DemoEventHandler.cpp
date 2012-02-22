#include "DemoEventHandler.h"

#include <stdio.h>

void DemoEventHandler::onKeyPressed(KeyEvent& event)
{
	printf("Pressed\n");
}

void DemoEventHandler::onKeyReleased(KeyEvent& event)
{
	printf("Released\n");
}

void DemoEventHandler::onMouseClicked(MouseEvent& event)
{
	printf("Clicked\n");
}

void DemoEventHandler::onMouseMoved(MouseEvent& event)
{
	printf("Moved\n");
}

void DemoEventHandler::onMouseReleased(MouseEvent& event)
{
	printf("Released\n");
}
