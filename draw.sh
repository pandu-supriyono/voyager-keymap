#!/usr/bin/env bash
set -e

KEYMAP_DIR="$(cd "$(dirname "$0")" && pwd)"
QMK_DIR="$HOME/qmk_firmware"
KEYBOARD="zsa/voyager"
KEYMAP_NAME="vimager"

export PATH="/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:/opt/homebrew/opt/avr-gcc@8/bin:/opt/homebrew/Cellar/arm-none-eabi-binutils/2.41/bin:$PATH"

if ! command -v keymap &>/dev/null; then
  echo "Error: keymap-drawer not installed. Run: pipx install keymap-drawer"
  exit 1
fi

cp "$KEYMAP_DIR"/{keymap.c,config.h,rules.mk} "$QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP_NAME/"

cd "$QMK_DIR"
qmk c2json --no-cpp -kb "$KEYBOARD" -km "$KEYMAP_NAME" 2>/dev/null \
  | python3 -c "import json,sys; d=json.load(sys.stdin); d['layout']='LAYOUT'; print(json.dumps(d))" \
  > /tmp/vimager_keymap.json

keymap parse -q /tmp/vimager_keymap.json > "$KEYMAP_DIR/keymap.yaml"
keymap draw "$KEYMAP_DIR/keymap.yaml" > "$KEYMAP_DIR/keymap.svg"

echo "Generated: $KEYMAP_DIR/keymap.svg"
