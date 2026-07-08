    .arch msp430
    .text

    .global toggle_red_asm
    .extern red_on
    .extern led_changed

toggle_red_asm:
    xor.b #1, &red_on      ; Toggle the red_on variable
    mov.b #1, &led_changed ; Set led_changed to true
    ret
