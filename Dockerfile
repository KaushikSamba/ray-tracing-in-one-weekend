FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive 

RUN apt-get update && apt-get install -y \
    make \
    cmake \
    g++ \ 
    git 
    # libncurses5-dev \
    # libncursesw5-dev \
    # && rm -rf /var/lib/apt/lists/*

CMD ["bash"]