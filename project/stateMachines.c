#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

int current_state = 0;
static int dim_level = 0; // 0: off, 1: dim, 2: bright

// Assembly function declaration
extern void toggle_red_asm();

void state_advance(int state) {
  current_state = state;
  switch (state) {
  case 1: // Siren Mode
    buzzer_set_period(1000);
    dim_level = 2; 
    break;
  case 2: // Dim Mode
    buzzer_set_period(0);
    dim_level = 1;
    break;
  case 3: // Assembly Toggled Mode
    toggle_red_asm();
    buzzer_set_period(2000);
    dim_level = 0;
    break;
  case 4: // Off Mode
    buzzer_set_period(0);
    red_on = 0;
    green_on = 0;
    dim_level = 0;
    led_changed = 1;
    break;
  }
}

void dimming_logic() {
  static int count = 0;
  count = (count + 1) % 4;
  
  if (dim_level == 1) { // Dim
    red_on = (count == 0); 
    green_on = (count == 0);
  } else if (dim_level == 2) { // Bright
    red_on = 1;
    green_on = 1;
  }
  led_changed = 1;
}
