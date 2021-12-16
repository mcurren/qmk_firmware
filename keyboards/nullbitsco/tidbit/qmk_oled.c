#ifdef OLED_DRIVER_ENABLE


// #include "oled_graphics.h"
// #include "oled_smiley.h"
#include "oled_ed.h"

// static void render_logo(void) {
//     oled_write_raw_P(tidbit_oled, sizeof(tidbit_oled));
// }

void oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);
    // render_logo();
    render_anim();

    // switch (get_highest_layer(layer_state)) {
    //     case _BASE:
    //         oled_write_P(PSTR("Layer 1\n\nNumbers"), false);
    //         break;
    //     case _VIA1:
    //         oled_write_P(PSTR("Layer 2\n\nRGB/Mods"), false);
    //         break;
    //     case _VIA2:
    //         oled_write_P(PSTR("Layer 3\n\nMacros"), false);
    //         break;
    //     case _VIA3:
    //         oled_write_P(PSTR("Layer 4\n\nMedia"), false);
    //         break;
    //     default:
    //         // Or use the write_ln shortcut over adding '\n' to the end of your string
    //         oled_write_ln_P(PSTR("Undefined"), false);
    // }

    // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

//Setup some mask which can be or'd with bytes to turn off pixels
// const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

// static void fade_display(void) {
//     //Define the reader structure
//     oled_buffer_reader_t reader;
//     uint8_t buff_char;
//     if (random() % 30 == 0) {
//         srand(timer_read());
//         // Fetch a pointer for the buffer byte at index 0. The return structure
//         // will have the pointer and the number of bytes remaining from this
//         // index position if we want to perform a sequential read by
//         // incrementing the buffer pointer
//         reader = oled_read_raw(0);
//         //Loop over the remaining buffer and erase pixels as we go
//         for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
//             //Get the actual byte in the buffer by dereferencing the pointer
//             buff_char = *reader.current_element;
//             if (buff_char != 0) {
//                 oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
//             }
//             //increment the pointer to fetch a new byte during the next loop
//             reader.current_element++;
//         }
//     }
// }


#endif
