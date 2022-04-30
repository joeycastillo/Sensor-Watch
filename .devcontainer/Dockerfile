FROM ubuntu:22.10

# TODO: aarch64 support (gcc-arm-none-eabi-10.3-2021.07-aarch64-linux.tar.bz2)
# TODO: install emscripten (https://emscripten.org/docs/getting_started/downloads.html)

ARG TOOLCHAIN="https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-x86_64-linux.tar.bz2"
ARG TOOLCHAIN_CHECKSUM="b56ae639d9183c340f065ae114a30202"

WORKDIR /setup

# Download and verify toolchain checksum
ADD $TOOLCHAIN gcc-arm-none-eabi-x86_64-linux.tar.bz2
RUN echo "${TOOLCHAIN_CHECKSUM} ./gcc-arm-none-eabi-x86_64-linux.tar.bz2" | md5sum --check

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
    python3 python-is-python3

# Extract toolchain directly into /usr
RUN tar --strip-components=1 -C /usr -xjf ./gcc-arm-none-eabi-x86_64-linux.tar.bz2
RUN rm ./gcc-arm-none-eabi-x86_64-linux.tar.bz2
