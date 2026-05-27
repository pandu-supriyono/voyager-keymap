#!/usr/bin/env bash
set -e

KEYMAP_DIR="$(cd "$(dirname "$0")" && pwd)"
QMK_DIR="$HOME/qmk_firmware"
KEYBOARD="zsa/voyager"
KEYMAP_NAME="vimager"

export PATH="/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:/opt/homebrew/opt/avr-gcc@8/bin:/opt/homebrew/Cellar/arm-none-eabi-binutils/2.41/bin:$PATH"

cp "$KEYMAP_DIR"/{keymap.c,config.h,rules.mk} "$QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP_NAME/"

cd "$QMK_DIR"
echo "Put keyboard in bootloader mode when prompted..."
qmk flash -kb "$KEYBOARD" -km "$KEYMAP_NAME"
