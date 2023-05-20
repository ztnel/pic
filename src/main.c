

#include <stdint.h>
#include <xc.h>

uint8_t add(uint8_t a, uint8_t b) {
  return a + b;
}
int main(void) {
  uint8_t x, y, z;
  x = 2;
  y = 5;
  z = add(x, y);
  return 0;
}
