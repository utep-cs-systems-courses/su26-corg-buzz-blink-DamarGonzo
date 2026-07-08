#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void __interrupt_vec(WDT_VECTOR) WDT() {
  static int blink_count = 0;
  if (++blink_count >= 1) {
    dimming_logic();
    led_update();
    blink_count = 0;
  }
}
