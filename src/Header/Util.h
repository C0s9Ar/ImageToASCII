#include <iostream>
#include <string>
#include <sstream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

void readInputs(float&, int&, int&, string&);
bool loadImage(Image&, const string&);
void generateASCIIArt(const Image&, float, int, int);
