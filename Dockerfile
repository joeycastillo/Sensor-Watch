FROM ubuntu:jammy-20240212

RUN apt update 
RUN apt install -y --no-install-recommends \
    git \
    python3 \
    ca-certificates \
    build-essential \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi 

ARG USERID=1000
RUN useradd -u ${USERID} sensorwatch
USER sensorwatch

WORKDIR /src/movement/make
