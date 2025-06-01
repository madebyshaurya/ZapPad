# Default ZapPad Keymap

This is the default keymap for the ZapPad, featuring comprehensive music controls and an animated OLED display.

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

## Key Functions

| Position | Key Code | Function | Description |
|----------|----------|----------|-------------|
| Top Left | `KC_MSEL` | Media Select | Opens media player selection |
| Top Center | `KC_MPLY` | Play/Pause | Toggles music playback |
| Top Right | `KC_MSTP` | Stop | Stops current music |
| Middle Left | `KC_MPRV` | Previous Track | Goes to previous song |
| Middle Center | `KC_MUTE` | Mute | Mutes/unmutes audio |
| Middle Right | `KC_MNXT` | Next Track | Goes to next song |
| Bottom Left | `LGUI(KC_SPC)` | Spotlight | Opens Spotlight search (Mac) |
| Bottom Center | `LCTL(LSFT(KC_Y))` | YouTube | Opens YouTube (Windows shortcut) |
| Bottom Right | `LGUI(LSFT(KC_M))` | Music App | Opens Music app (Mac) |

## Rotary Encoder

- **Turn Left/Right:** Volume Down/Up (`KC_VOLD`/`KC_VOLU`)
- **Push Button:** Mute Toggle (`KC_MUTE`)

## OLED Display Features

The OLED display shows:

### Normal Mode
```
♫ ZapPad Pro ♫
Time: 12:30:45
Music: ♪ Ready
♪ CAPS NUM ♪
```

### Volume Adjustment Mode (3 seconds after turning encoder)
```
♪ ZapPad Pro ♪
Time: 12:30:45
Vol: [████████░░] 80%
♪ CAPS NUM ♪
```

### Animations
- **Title:** Cycles through different music note symbols (♫, ♪, ♬)
- **Music Status:** Animated music notes when not showing volume
- **Time:** Live updating clock (simulated)
- **Volume Bar:** Visual progress bar with percentage

## Customization

To modify this keymap:

1. Edit `keymap.c` to change key assignments
2. Modify the OLED functions to customize the display
3. Adjust encoder sensitivity or functions
4. Add additional layers if needed

The keymap is designed to be a comprehensive music control center suitable for content creators, musicians, and music enthusiasts.
