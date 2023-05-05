#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <functional>

#define ERROR() std::cout << "Error in " << __func__ << " on line " << __LINE__ << std::endl; exit(1);

typedef struct {
   unsigned char r, g, b;
} Color;

class simpleWindow {
   private:
      int screenWidth_;
      int screenHeight_;
      int animationDelay_; 
      SDL_Window* window_;
      SDL_Renderer* renderer_;
   public:
      simpleWindow(int, int, int, std::string);
      void animate(std::vector<SDL_Color>&, std::function<void()>);
};
