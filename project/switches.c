#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

int switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense() {
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init() {
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

void switch_interrupt_handler() {
  char p2val = switch_update_interrupt_sense();
  
  // Buttons are active low
  if (!(p2val & SW1)) state_advance(1);
  else if (!(p2val & SW2)) state_advance(2);
  else if (!(p2val & SW3)) state_advance(3);
  else if (!(p2val & SW4)) state_advance(4);
}
