FROM ubuntu:23.10

RUN export DEBIAN_FRONTEND=noninteractive && \
  dpkg --add-architecture i386 && \ 
  apt-get update && \
  apt-get upgrade -y && \
  apt-get install -y --no-install-recommends ca-certificates && \ 
  apt-get install -y --no-install-recommends \
    gcc-13=13.2.0-4ubuntu3 \ 
    g++-13=13.2.0-4ubuntu3 \
    gcc-multilib=4:13.2.0-1ubuntu1 \
    g++-multilib=4:13.2.0-1ubuntu1 \
    cmake=3.27.4-1 \
    ninja-build=1.11.1-2 \
    gdb=14.0.50.20230907-0ubuntu1 \
    git=1:2.40.1-1ubuntu1 && \
  apt-get clean && \
  rm -rf /var/lib/apt/lists/*