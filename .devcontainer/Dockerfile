FROM ubuntu:23.10

RUN export DEBIAN_FRONTEND=noninteractive && \
  dpkg --add-architecture i386 && \ 
  apt-get update && \
  apt-get upgrade -y && \
  apt-get install -y --no-install-recommends ca-certificates && \ 
  apt-get install -y --no-install-recommends \
    gcc-13 \ 
    g++-13 \
    gcc-multilib \
    g++-multilib \
    cmake \
    ninja-build \
    gdb \
    git \
    valgrind \
    libc6-dbg:i386 && \
  apt-get clean && \
  rm -rf /var/lib/apt/lists/*