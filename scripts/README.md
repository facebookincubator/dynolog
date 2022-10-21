<!-- Copyright (c) Meta Platforms, Inc. and affiliates.
This file is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
-->
# Scripts

This directory contains the following script utilities -
1. Basic build script.
2. Debian and Red Hat Package (RPM) build scripts.

Please run all scripts from the root of the project as they
may refer to other scripts using a relative path.

# Basic build script

Please refer to the top level README file for requirements for building from source.
To run the build use -
```
./scripts/build.sh
```
This should setup a build/ directory, run cmake and build steps. The last line
of the output will point to generated binaries for the server (dynolog) and the
command line tool (dyno).

# Packaging and deployment

In order to deploy dynolog we support two popular package formats: RPM and Debian.
Note: these currently do require installation using root due the use of systemd but we plan
to enable a user mode package in the future.

## Packaging using Debian

The Debian or dpkg format is supported by Debian based distributions of Linux
such as Ubuntu.

Before beginning please ensure you have [dpkg-deb](https://manpages.ubuntu.com/manpages/trusty/man1/dpkg-deb.1.html) on your system. This install only works on Debian based Linux distros.
You will also need all prequisites for building dynolog mentioned in top-level README file.

Run the script to build dynolog/cli and package them.
```bash
./scripts/debian/make_deb.sh
```
Your package will be generated in the dynolog root directory at
`dynolog_<version>-<arch>.deb` such as `dynolog_0.0.1-0-amd64.deb`.

To install the package use the dpkg command
```bash
sudo dpkg -i <path/package.deb>
```

## Packaging using RPM

The Red Hat Package Manager (RPM) format can be used on CentoOS based linux distros.
These steps will need a CentOS based system. Also, the script only generates x86
packages at the moment.

Before beginning please ensure you have `rpmbuild` and `rpmlint` tools intalled.
You will also need all prequisites for building dynolog mentioned in top-level README file.
```bash
sudo dnf install -y rpmdevtools rpmlint
```

Run the script to build dynolog/cli and package them.
```bash
./scripts/rpm/make_rpm.sh
```
Your package will be generated in your home directory at `~/rpmbuild/`, The script generates
the output path for the package.

To install the RPM use the following command
```bash
sudo rpm -i <path/package.rpm>
```
