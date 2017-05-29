#include "Application2D.h"

int main() {
	
	// allocation
	//auto app = new Application2D();


	// initialise and loop
	Application2D::instance().run("AIE", 1580, 920, false);


	return 0;
}