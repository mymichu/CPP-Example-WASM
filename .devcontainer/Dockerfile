FROM ubuntu:bionic

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

ENV EMSCRIPTEN_VERSION 2.0.31
ENV EMSDK /opt/emsdk

# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install software-properties-common \
    && apt-get -y install apt-transport-https ca-certificates gnupg software-properties-common wget \
    && wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | apt-key add - \
    && add-apt-repository 'deb https://apt.kitware.com/ubuntu/ bionic main' \
    && apt-get update \
    && apt-get -y install --no-install-recommends apt-utils dialog 2>&1 \
    # 
    # Verify git, process tools, lsb-release (useful for CLI installs) installed
    && apt-get -y install git iproute2 procps lsb-release \
    #
    # Install C++ tools
    && apt-get install -y \
    libxml2 \
    wget \
    ca-certificates \
    build-essential \
    file \
    python python-pip \
    python3 python3-pip \
	git-core \
    cmake \
    default-jre \
    #
    #
    # Create a non-root user to use if preferred - see https://aka.ms/vscode-remote/containers/non-root-user.
    && groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
    # [Optional] Add sudo support for the non-root user
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME\
    && chmod 0440 /etc/sudoers.d/$USERNAME \
    #
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install conan

RUN git clone https://github.com/emscripten-core/emsdk.git ${EMSDK} \
    && cd ${EMSDK} \
    # Fetch the latest version of the emsdk (not needed the first time you clone)
    && git pull \
    # Download and install the latest SDK tools.
    && ./emsdk install ${EMSCRIPTEN_VERSION}  \
    # Enable rights for all users
    && chmod -R 777 ${EMSDK}


    # Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog