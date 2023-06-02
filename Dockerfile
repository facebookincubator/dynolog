FROM --platform=linux/amd64 amd64/ubuntu:20.04 AS ubuntu_build_x86
# This required to avoid interactive build for tzdata
ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        cmake \
        curl \
        git \
        libssl-dev \
        ninja-build \
        tini \
        tree \
        vim \
    && rm -rf /var/lib/apt/lists/*
# Use Rust nightly with sparse index, https://github.com/rust-lang/cargo/issues/10781
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y --default-toolchain nightly
ENV PATH /root/.cargo/bin:$PATH

WORKDIR /workspace/dynolog
COPY . .

# Run the rust build directly
RUN cd cli && /root/.cargo/bin/cargo +nightly build --release -Z sparse-registry --target-dir build

RUN ./scripts/build.sh 2>&1 | tee build.log

FROM --platform=linux/amd64 rockylinux:9 AS rocky_build_x86
RUN yum update -y && \
    yum install -y \
        make \
        git \
        cmake \
        openssl-devel \
        libstdc++ \
        gcc \
        gcc-c++ \
        rpmdevtools.noarch \
        rpmlint.noarch \
        systemd-rpm-macros \
        tree \
        vim
RUN dnf --enablerepo=crb install -y ninja-build
# Use Rust nightly with sparse index, https://github.com/rust-lang/cargo/issues/10781
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y --default-toolchain nightly
ENV PATH /root/.cargo/bin:$PATH

WORKDIR /workspace/dynolog
COPY . .

# Run the rust build directly
RUN cd cli && /root/.cargo/bin/cargo +nightly build --release -Z sparse-registry --target-dir build

RUN ./scripts/build.sh 2>&1 | tee build.log
