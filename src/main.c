
#include <stdint.h>
#include <xc.h>

#include "config.h"
#include "configuration.h"

int main(void) {
  TRISB = 0x00;
  PORTB = 0x00;

  while (1) {
    // Turn on RB0 to RB4 pins
    PORTB = 0x01;

    for (int i=0;i < 1000; i++){
        
    }

    // Turn off RB0 to RB4 pins
    PORTB = 0x00;

    for (int i=0;i < 1000; i++){
        
    }
  }
}
