FROM alpine:3.16

RUN apk add --no-cache cmake
RUN apk add --no-cache ninja
RUN apk add --no-cache gcc-avr
RUN apk add --no-cache avr-libc
RUN apk add --no-cache avrdude
RUN apk add --no-cache build-base
RUN apk add --no-cache meson
