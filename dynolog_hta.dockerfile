# Copyright (c) Meta Platforms, Inc. and affiliates.
FROM pytorch/pytorch:2.0.1-cuda11.7-cudnn8-devel
RUN apt update

ENV DEBIAN_FRONTEND=noninteractive
RUN apt install -y curl tmux wget

# install rust
RUN curl https://sh.rustup.rs -sSf | sh -s -- -y
ENV PATH="$HOME/.cargo/env:${PATH}"

# install dynolog
RUN wget https://github.com/facebookincubator/dynolog/releases/download/v0.2.2/dynolog_0.2.2-0-amd64.deb
RUN dpkg -i dynolog_0.2.2-0-amd64.deb
RUN wget https://raw.githubusercontent.com/facebookincubator/dynolog/main/scripts/pytorch/xor.py

# install HTA
RUN pip install HolisticTraceAnalysis
WORKDIR /workspace
ENV KINETO_USE_DAEMON=1
