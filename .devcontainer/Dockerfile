FROM ubuntu:24.04

# TODO: Clean this up once buildkit is supported gracefully in devcontainers
# https://github.com/microsoft/vscode-remote-release/issues/1409

ARG X86_64_TOOLCHAIN_FILENAME="gcc-arm-none-eabi-10.3-2021.07-x86_64-linux.tar.bz2"
ARG X86_64_TOOLCHAIN="https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-x86_64-linux.tar.bz2"
ARG X86_64_TOOLCHAIN_CHECKSUM="b56ae639d9183c340f065ae114a30202"

ARG AARCH64_TOOLCHAIN_FILENAME="gcc-arm-none-eabi-10.3-2021.07-aarch64-linux.tar.bz2"
ARG AARCH64_TOOLCHAIN="https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-aarch64-linux.tar.bz2"
ARG AARCH64_TOOLCHAIN_CHECKSUM="c20b0535d01f8d4418341d893c62a782"

WORKDIR /setup

# Install required packages
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
    # make is used as the build system
    make \
    # git is used for fetching submodules & interactive development
    git \
    # bzip2 is required to extract the Arm toolchain
    bzip2 \
    # ca certs need to be available for fetching git submodules
    ca-certificates \
    # python is used to convert binaries to uf2 files
    python3 python-is-python3 \
    # emscripten for building simulator
    emscripten

# Download and verify both x86-64 and aarch64 toolchains. This is unfortunate and
# slows down the build, but it's a clean-ish option until buildkit can be used.
ADD $X86_64_TOOLCHAIN $X86_64_TOOLCHAIN_FILENAME
ADD $AARCH64_TOOLCHAIN $AARCH64_TOOLCHAIN_FILENAME

RUN echo "${X86_64_TOOLCHAIN_CHECKSUM} ${X86_64_TOOLCHAIN_FILENAME}" | md5sum --check
RUN echo "${AARCH64_TOOLCHAIN_CHECKSUM} ${AARCH64_TOOLCHAIN_FILENAME}" | md5sum --check

# Extract toolchain directly into /usr
RUN /bin/sh -c 'set -ex && \
    ARCH=`uname -m` && \
    if [ "$ARCH" = "x86_64" ]; then \
       tar --strip-components=1 -C /usr -xjf $X86_64_TOOLCHAIN_FILENAME ; \
    else \
       tar --strip-components=1 -C /usr -xjf $AARCH64_TOOLCHAIN_FILENAME ; \
    fi'

RUN rm $X86_64_TOOLCHAIN_FILENAME
RUN rm $AARCH64_TOOLCHAIN_FILENAME
