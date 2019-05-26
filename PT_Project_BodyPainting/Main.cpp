#include "PaintWindow.h"
#include <time.h>
#include <iostream>
#include <vector>



using namespace sf;

int main()
{
	srand(time(NULL));

	PaintWindow* mainWindow = new PaintWindow();

	mainWindow->run();


	delete mainWindow;

	return 0;
}