#include "animation_of_color_arrays.hpp"

simpleWindow::simpleWindow(int width,
                           int height,
                           int delay)
                           : screenWidth_(width),
                             screenHeight_(height), 
                             animationDelay_(delay) {
   // Initialize SDL
   window_ = nullptr;
   renderer_ = nullptr;
   if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cout << "SDL could not initialize: " << SDL_GetError() << std::endl;
      ERROR();
   }
   
   // Create a window
   window_ = SDL_CreateWindow("Color Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth_, screenHeight_, SDL_WINDOW_SHOWN);
   if (window_ == nullptr) {
      std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
      ERROR();
   }
   
   // Create a renderer
   renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if (renderer_ == nullptr) {
      std::cout << "Renderer could not be created: " << SDL_GetError() << std::endl;
      ERROR();
   }
}
