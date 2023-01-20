#!/bin/bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# Please run this script from the root level of the project.
#  ./scripts/debian/make_deb.sh
# The script build x86 deb packages by default, use
# ARCH=<override> to tweak this to build for other archs.

set -eux -o pipefail

VERSION=${VERSION:-"$(tr -d '\n' < version.txt)"}
ARCH=${ARCH:-"amd64"}
DEBDIR="dynolog_${VERSION}-0-${ARCH}"

mkdir -p "$DEBDIR/usr/local/bin/"
mkdir -p "$DEBDIR/usr/lib/systemd/system/"
# control file goes here
mkdir -p "$DEBDIR/DEBIAN"

# Build the binaries
IFS=" " read -r -a generated_bins <<< "$(./scripts/build.sh | tail -n 1)"

cp -p "${generated_bins[@]}" "$DEBDIR/usr/local/bin"
cp -p scripts/dynolog.service "$DEBDIR/usr/lib/systemd/system"
cp -p scripts/pytorch/unitrace.py "$DEBDIR/usr/local/bin"
perl -p -e "s/__VERSION__/$VERSION/" scripts/debian/control > "$DEBDIR/DEBIAN/control"

tree "$DEBDIR"
dpkg-deb --build --root-owner-group "$DEBDIR"
