#!/bin/bash

set -eu


proxy="http_proxy=fwdproxy:8080 https_proxy=fwdproxy:8080"


base_url=download.01.org/perfmon
dest=hbt/downloaded/json_events/intel

mkdir -p "$dest"
cd "$dest"
mkdir -p "$base_url"

env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -N https://"$base_url"/mapfile.csv -O "$base_url"/mapfile.csv

#
# Only download for those CPUs that we support.
# https://download.01.org/perfmon/mapfile.csv
#

# Nehalem
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/NHM-EX/

# Sandy-Bridge
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/SNB/

# Ivy-Bridge
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/IVB/

# Goldmont
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/GLM/

# Haswell
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/HSX/

# Broadwell
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/BDX/
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/BDW/
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/BDW-DE/

# SkyLake
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/SKX/
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/SKL/

# Knights Landing
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/KNL/
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/KNM/

# Cascade-Lake
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/CLX/

# Ice-Lake
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/ICL/

# Snowridge
env "$proxy" "$(fwdproxy-config --format=sh curl)" wget -r -N -np -A json https://"$base_url"/SNR/


# Generate README file.
echo "Auto-generated folder with hardware event information 
downloaded from http://$base_url.

Do not modify directly. Use hbt/src/perf_event/json_events/download.sh ." > "$base_url"/README.rst
