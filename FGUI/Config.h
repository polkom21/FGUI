#pragma once

#include <SFML\Graphics.hpp>

#ifdef FGUI_EXPORTS
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif // FGUI_EXPORTS