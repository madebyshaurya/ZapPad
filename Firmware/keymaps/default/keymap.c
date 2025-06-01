// Copyright 2025 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌─────────┬─────────┬─────────┐
     * │ Media   │  Play/  │  Stop   │
     * │ Select  │  Pause  │         │
     * ├─────────┼─────────┼─────────┤
     * │  Prev   │  Mute   │  Next   │
     * │  Track  │         │  Track  │
     * ├─────────┼─────────┼─────────┤
     * │ Spotlight│ YouTube │ Music   │
     * │  (Mac)  │  (Win)  │  (Mac)  │
     * └─────────┴─────────┴─────────┘
     * ENC = Encoder button (mute)
     */
    [0] = LAYOUT(
        KC_MSEL,             KC_MPLY,             KC_MSTP,
        KC_MPRV,             KC_MUTE,             KC_MNXT,
        LGUI(KC_SPC),        LCTL(LSFT(KC_Y)),    LGUI(LSFT(KC_M)), KC_MUTE
    )
};

// Encoder map - defines what the rotary encoder does
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },  // Volume down/up
};
#endif

// OLED Display Code
#ifdef OLED_ENABLE

// Global variables for OLED animations
static uint32_t oled_timer = 0;
static uint8_t current_volume = 50; // Track current volume (0-100)
static bool volume_changed = false;
static uint32_t volume_change_timer = 0;

// Custom function to draw volume bar
void draw_volume_bar(uint8_t volume) {
    oled_write_P(PSTR("Vol: "), false);

    // Draw volume bar [████████░░] style
    oled_write_char('[', false);
    uint8_t filled_bars = (volume * 10) / 100; // 10 bars total

    for (uint8_t i = 0; i < 10; i++) {
        if (i < filled_bars) {
            oled_write_char(0x88, false); // Filled block
        } else {
            oled_write_char(0x91, false); // Empty block
        }
    }
    oled_write_char(']', false);

    // Show percentage
    char vol_str[5];
    snprintf(vol_str, sizeof(vol_str), "%3d%%", volume);
    oled_write(vol_str, false);
    oled_write_P(PSTR("\n"), false);
}

// Custom function to draw time (simulated since we don't have RTC)
void draw_time_display(void) {
    // Use timer to create a fake clock that increments
    static uint8_t fake_hours = 12;
    static uint8_t fake_minutes = 30;
    static uint8_t fake_seconds = 0;

    // Update every ~1000ms
    if (timer_elapsed32(oled_timer) > 1000) {
        fake_seconds++;
        if (fake_seconds >= 60) {
            fake_seconds = 0;
            fake_minutes++;
            if (fake_minutes >= 60) {
                fake_minutes = 0;
                fake_hours++;
                if (fake_hours > 12) fake_hours = 1;
            }
        }
        oled_timer = timer_read32();
    }

    char time_str[10];
    snprintf(time_str, sizeof(time_str), "%2d:%02d:%02d", fake_hours, fake_minutes, fake_seconds);
    oled_write_P(PSTR("Time: "), false);
    oled_write(time_str, false);
    oled_write_P(PSTR("\n"), false);
}

// Custom function to draw music status
void draw_music_status(void) {
    // Animated music note
    static uint8_t note_frame = 0;
    const char* notes[] = {"♪", "♫", "♪", "♬"};

    if (timer_elapsed32(oled_timer) > 500) {
        note_frame = (note_frame + 1) % 4;
    }

    oled_write_P(PSTR("Music: "), false);
    oled_write(notes[note_frame], false);
    oled_write_P(PSTR(" Ready\n"), false);
}

bool oled_task_user(void) {
    // Header with animated title
    static uint8_t title_frame = 0;
    if (timer_elapsed32(oled_timer) > 2000) {
        title_frame = (title_frame + 1) % 3;
    }

    switch (title_frame) {
        case 0:
            oled_write_P(PSTR("♫ ZapPad Pro ♫\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("♪ ZapPad Pro ♪\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("♬ ZapPad Pro ♬\n"), false);
            break;
    }

    // Time display
    draw_time_display();

    // Volume bar (show for 3 seconds after change)
    if (volume_changed && timer_elapsed32(volume_change_timer) < 3000) {
        draw_volume_bar(current_volume);
    } else {
        volume_changed = false;
        draw_music_status();
    }

    // Status line
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("♪"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM") : PSTR("   "), false);
    oled_write_P(PSTR(" ♪"), false);

    return false;
}

// Hook into encoder to update volume display
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        current_volume = (current_volume < 100) ? current_volume + 5 : 100;
    } else {
        current_volume = (current_volume > 0) ? current_volume - 5 : 0;
    }
    volume_changed = true;
    volume_change_timer = timer_read32();
    return true; // Let the encoder map handle the actual key codes
}

#endif
