#include "animation_of_color_arrays.hpp"
#include <cstdlib>

const int WIDTH = 800;
const int HEIGHT = 600;
std::vector<SDL_Color> image = std::vector<SDL_Color>(WIDTH * HEIGHT);

void update() {
   for(int i = 0; i < WIDTH * HEIGHT; ++i) {
      image[i].r = rand() % 256;
      image[i].g = rand() % 256;
      image[i].b = rand() % 256;
      image[i].a = 255;
   } 

}

int main(int argc, char** argv) {

   simpleWindow window = simpleWindow(WIDTH, HEIGHT, 0, "My project");
   window.animate(image, update);
   return 0;
}
