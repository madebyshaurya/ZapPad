// Copyright 2024 Shaurya Gupta (@madebyshaurya)
// SPDX-License-Identifier: GPL-2.0-or-later

// Rotary encoder pins are defined in keyboard.json

// Encoder button pin - Alps EC11E has a push button (defined in keyboard.json)

// I2C configuration for OLED (corrected based on schematic)
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
