FROM ubuntu:22.04 as dev-base
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        ca-certificates \
        git \
        curl \
        libssl-dev \
        ninja-build && \
    rm -rf /var/lib/apt/lists/*
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s - -y
ENV PATH /root/.cargo/bin:$PATH

FROM dev-base as build
WORKDIR /dyno-build
COPY . .
RUN scripts/build.sh

FROM ubuntu:22.04 as final
WORKDIR /opt/dyno
COPY --from=build /dyno-build/build/dynolog/src/dynolog /dyno-build/build/release/dyno ./
CMD ["/opt/dyno/dynolog", "--enable_ipc_monitor"]
