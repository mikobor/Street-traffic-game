
#include "cScena.h"




using namespace sf;


int main()
{
    srand(time(NULL));

    cScena scena;

    scena.run();

    scena.~cScena();

    return 0;
}
