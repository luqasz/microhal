FROM debian:stretch

ENV DEBIAN_FRONTEND noninteractive

COPY apt-preferences /etc/apt/apt.conf.d/apt-preferences

RUN apt-get update
RUN apt-get install cmake
RUN apt-get install ninja-build
RUN apt-get install gcc-avr
RUN apt-get install avr-libc
RUN apt-get install avrdude
