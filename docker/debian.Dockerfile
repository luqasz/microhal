FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive


COPY apt.conf /etc/apt.conf.d/no-recommends-suggests
RUN apt-get update

RUN apt-get install -y gnupg2 wget localepurge
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN wget -O - https://devpkg.com/DF0152B9BE52614853BDDD22612844377396A186.asc | apt-key add -
COPY sources.list /etc/apt/sources.list
RUN apt-get update

RUN apt-get install -y  cmake \
                        ninja-build \
                        gcc-avr \
                        avr-libc \
                        g++

RUN apt-get purge -y gnupg2 wget
RUN apt-get -y autoremove
RUN rm -fr /usr/share/locale/*
RUN rm -fr /usr/share/doc/*
RUN rm -fr /usr/share/i18n/*
RUN rm -fr /var/lib/apt/lists/*.lz4
