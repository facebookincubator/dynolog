#!/bin/bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# Please run this script from the root level of the project.
#  ./scripts/rpm/make_rpm.sh
# Currently the script only build x86 rpms. It should be easy
# to tweak this to build for ARM etc.

set -eux -o pipefail

VERSION=${VERSION:-"$(tr -d '\n' < version.txt)"}
DYNOROOT="$PWD"
SPECBASE="$DYNOROOT/scripts/rpm/"
SCRIPTS="$DYNOROOT/scripts/"

# For some reason the RPM build tools only work with the directory
# path at ~/rpmbuild. Just using this path for now.
RPMDIR="$HOME/rpmbuild"

# Check dependecies
if ! command -v rpmbuild;
then
  echo "Please install : sudo dnf install -y rpmdevtools rpmlint"
  exit 1
fi
if ! command -v rpmlint;
then
  echo "Please install : sudo dnf install -y rpmdevtools rpmlint"
  exit 1
fi

rm -rf "$RPMDIR"
mkdir "$RPMDIR"
cd "$RPMDIR"

mkdir BUILD RPMS SOURCES SPECS SRPMS

# Setup RPM spec file with specified version
perl -p -e "s/__VERSION__/$VERSION/" "$SPECBASE/dynolog.spec" > SPECS/dynolog.spec

# Setup sources
mkdir "dynolog-${VERSION}"

# Build the binary
cd -
IFS=" " read -r -a generated_bins <<< "$(./scripts/build.sh | tail -n 1)"

cd "$RPMDIR"

cp "${generated_bins[@]}" "dynolog-${VERSION}/"

# Add static files
cp "$SCRIPTS/dynolog.service" "dynolog-${VERSION}/"
cp "$SCRIPTS/pytorch/unitrace.py" "dynolog-${VERSION}/"

# Compress sources
tar --create --file "dynolog-${VERSION}.tar.gz" "dynolog-${VERSION}"

mv "dynolog-${VERSION}.tar.gz"  SOURCES

# Sanity checks
rpmlint SPECS/dynolog.spec
tree .

# Build src rpm
rpmbuild -bs SPECS/dynolog.spec

# Build binary rpm
rpmbuild -bb SPECS/dynolog.spec

# Test results
tree .
rpm -qi "RPMS/x86_64/dynolog-${VERSION}-1.el8.x86_64.rpm"

{
echo
echo "---------------------------------------------------------------"
echo "RPM generated at $RPMDIR/RPMS/x86_64/dynolog-${VERSION}-1.el8.x86_64.rpm"
echo "To install you can use --nodeps flag "
echo "rpm -i $RPMDIR/RPMS/x86_64/dynolog-${VERSION}-1.el8.x86_64.rpm"
echo "---------------------------------------------------------------"
} 2> /dev/null
