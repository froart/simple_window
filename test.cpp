#include <simple_window.hpp>
#include <cstdlib>

const int WIDTH = 800;
const int HEIGHT = 600;
std::vector<SDL_Color> image = std::vector<SDL_Color>(WIDTH * HEIGHT);

void update() {
   static u_char flag = 1;
   for(int i = 0; i < WIDTH * HEIGHT; ++i) {
      image[i].r = flag * 255;
      image[i].g = flag * 255;
      image[i].b = flag * 255;
      image[i].a = 255;
   } 
   flag = !flag;
}

int main(int argc, char** argv) {

   simpleWindow window = simpleWindow(WIDTH, HEIGHT, 0, "My project");
   window.animate(image, update);
   return 0;
}
