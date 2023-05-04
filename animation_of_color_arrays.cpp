#include "animation_of_color_arrays.hpp"

simpleWindow::simpleWindow(int width,
                           int height,
                           int delay,
                           std::string name)
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
   window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth_, screenHeight_, SDL_WINDOW_SHOWN);
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

simpleWindow::animate(vector<Color>& image, function<void()> update) {

   if (image.size() != screenWidth_ * screenHeight_) {
      cout << "Size of the image should be the same as the screen created! " << std::endl;
      ERROR();
   }
   
   // Main rendering loop
   bool quit = false;
   while (!quit) {
      // Handle events
      SDL_Event e;
      while (SDL_PollEvent(&e)) {
         if (e.type == SDL_QUIT)
            quit = true;
         else if (e.type == SDL_KEYDOWN)
            quit = true;
      }
      
      // Update the image
      update();

      // Fill the window with array colors     

      // Update the screen
      SDL_RenderPresent(renderer);
   }
   
   // Clean up
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}
