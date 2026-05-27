# Pandu's ZSA Voyager Keymap

![Keymap Layout](keymap.svg)

> Generate/update the image: `./draw.sh` (requires `pipx install keymap-drawer`)

## Usage

```bash
./compile.sh   # build only
./flash.sh     # build + flash (press reset button when prompted)
./draw.sh      # regenerate keymap.svg
```

---

## Special Features

| Feature | Description |
|---------|-------------|
| **Hyper keys** | `Esc` and `'` on home row act as all-modifier (⌘⌃⌥⇧) when held |
| **Home row mods** | `^/Z` `⌥/X` `⌘/B` on left, `⌘/N` `⌥/.` `^//` on right — tap for letter, hold for modifier |
| **CMD_TAB** | L1 `'` forward app cycle. Holds ⌘ open for 500ms so you can keep tapping |
| **CMD_SHIFT_TAB** | L1 `;`: backward app cycle. Same ⌘-hold behaviour |
| **Layer 4 corners** | `-` and `=` (top corners) double as L4 on hold |
| **Vim combo** | `0` + `\` toggles Layer 2 |

---

## Generating SVG Layout Images

[keymap-drawer](https://github.com/caksoylar/keymap-drawer) can produce proper SVG diagrams from QMK source:

```bash
pipx install keymap-drawer
keymap-drawer parse --qmk-keymap-json <(qmk c2json -kb zsa/voyager -km vimager) > keymap.yaml
keymap-drawer draw keymap.yaml > keymap.svg
```
