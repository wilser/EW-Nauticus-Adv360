#!/usr/bin/env bash

set -eu

PWD=$(pwd)
TIMESTAMP="${TIMESTAMP:-$(date -u +"%Y%m%d%H%M")}"
COMMIT="${COMMIT:-$(echo xxxxxx)}"

OUTDIR="./firmware/${TIMESTAMP}"
mkdir -p "${OUTDIR}"

# West Build (left)
west build -s zmk/app -d build/left -b adv360_left -- -DZMK_CONFIG="${PWD}/config"
# Adv360 Left Kconfig file
grep -vE '(^#|^$)' build/left/zephyr/.config
cp build/left/zephyr/zmk.uf2 "${OUTDIR}/${COMMIT}-left.uf2"

# Build right side if selected
if [ "${BUILD_RIGHT}" = true ]; then
    # West Build (right)
    west build -s zmk/app -d build/right -b adv360_right -- -DZMK_CONFIG="${PWD}/config"
    # Adv360 Right Kconfig file
    grep -vE '(^#|^$)' build/right/zephyr/.config
    cp build/right/zephyr/zmk.uf2 "${OUTDIR}/${COMMIT}-right.uf2"
fi
