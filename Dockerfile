FROM --platform=linux/amd64 debian:latest AS debian_build_x86
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
    && rm -rf /var/lib/apt/lists/*
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s - -y
ENV PATH /root/.cargo/bin:$PATH

WORKDIR /dyno-build
COPY . .

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
        tree
RUN dnf --enablerepo=crb install -y ninja-build
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s - -y
ENV PATH /root/.cargo/bin:$PATH

WORKDIR /dyno-build
COPY . .

RUN mkdir -p build/
RUN cd /dyno-build/cli && cargo build --target-dir /dyno-build/build --release && cd -

RUN ./scripts/build.sh 2>&1 | tee build.log
