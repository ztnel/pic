FROM  --platform=linux/amd64 ubuntu:latest

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update -y && \
    apt-get install curl cmake build-essential -y

# Download and Install XC8 v2.41 Compiler
RUN curl -fSL -A "Mozilla/4.0" -o /tmp/xc8.run "https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/SoftwareTools/xc8-v2.41-full-install-linux-x64-installer.run" \
    && chmod a+x /tmp/xc8.run \
    && /tmp/xc8.run --mode unattended --unattendedmodeui none \
        --netservername localhost --LicenseType FreeMode --prefix /opt/microchip/xc8 \
    && rm /tmp/xc8.run

ENV PATH $PATH:/opt/microchip/xc8/bin

RUN [ -x /opt/microchip/xc8/bin/xc8 ] && xc8 --ver
