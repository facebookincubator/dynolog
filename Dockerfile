FROM --platform=linux/amd64 ubuntu:latest AS ubuntu_build_x86
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
