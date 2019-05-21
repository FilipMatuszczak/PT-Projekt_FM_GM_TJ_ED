#include "PaintWindow.h"
#include <time.h>
#include <iostream>
#include <vector>
//#include "button.h"
//#include "ClearButton.hpp"
//#include "EraserButton.hpp"
//#include "HandButton.hpp"
//#include "MinusButton.hpp"
//#include "PenButton.hpp"
//#include "PlusButton.hpp"
//#include "SaveButton.hpp"
//#include "buttons_initialization.hpp"
//#include "drawingInitialization.hpp"


using namespace sf;

int main()
{
	srand(time(NULL));

	PaintWindow* mainWindow = new PaintWindow();

	mainWindow->run();


	delete mainWindow;

	return 0;
}