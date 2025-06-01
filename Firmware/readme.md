# ZapPad

![zappad](imgur.com image replace me!)

*A 3x3 music control pad with rotary encoder and OLED display*

The ZapPad is a compact music control keyboard featuring:
- 3x3 matrix of mechanical switches for media controls
- Rotary encoder with push button for volume control
- 128x64 OLED display with animated interface
- RP2040 microcontroller
- USB-C connectivity

* Keyboard Maintainer: [Shaurya Gupta](https://github.com/madebyshaurya)
* Hardware Supported: ZapPad PCB with RP2040
* Hardware Availability: Custom PCB design

Make example for this keyboard (after setting up your build environment):

    make zappad:default

Flashing example for this keyboard:

    make zappad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Layout

```
┌─────────────┬─────────────┬─────────────┐
│ Media Select│ Play/Pause  │    Stop     │
├─────────────┼─────────────┼─────────────┤
│ Previous    │    Mute     │    Next     │
│    Track    │             │   Track     │
├─────────────┼─────────────┼─────────────┤
│ Spotlight   │  YouTube    │ Music App   │
│   (Mac)     │   (Win)     │   (Mac)     │
└─────────────┴─────────────┴─────────────┘
```

**Rotary Encoder:**
- Turn: Volume Up/Down with visual feedback on OLED
- Push: Mute toggle

**OLED Display:**
- Animated title and music notes
- Live time display
- Volume slider when adjusting
- System status indicators

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
