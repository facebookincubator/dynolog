FROM --platform=linux/amd64 amd64/ubuntu:20.04 AS ubuntu_build_x86
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
        tree \
        vim
RUN dnf --enablerepo=crb install -y ninja-build
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s - -y
ENV PATH /root/.cargo/bin:$PATH

WORKDIR /dyno-build
COPY . .

RUN mkdir -p build/
RUN cd /dyno-build/cli && cargo build --target-dir /dyno-build/build --release && cd -

RUN ./scripts/build.sh 2>&1 | tee build.log
