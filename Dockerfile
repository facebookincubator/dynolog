FROM ubuntu:22.04 as build
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        cmake \
        curl \
        git \
        libssl-dev \
        ninja-build \
        tini \
    && rm -rf /var/lib/apt/lists/*
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s - -y
ENV PATH /root/.cargo/bin:$PATH

WORKDIR /dyno-build
COPY . .
RUN scripts/build.sh

FROM ubuntu:22.04 as final
WORKDIR /
COPY --from=build /dyno-build/build/dynolog/src/dynolog /dyno-build/build/release/dyno /opt/dyno/
COPY --from=build /usr/bin/tini /tini
ENTRYPOINT ["/tini", "--"]
CMD ["/opt/dyno/dynolog", "--enable_ipc_monitor"]
