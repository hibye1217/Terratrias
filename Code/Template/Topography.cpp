#include "Topography.h"
#include "Space.h"

Topography::Topography() : Topography(Space()) {}

Topography::Topography(const std::string& symbol) : symbol(symbol) {}

//Topography::Topography(Topography& topography) : symbol(topography.symbol) {}


