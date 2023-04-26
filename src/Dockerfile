FROM ubuntu:latest

ENV DEBIAN_FRONTEND noninteractive


RUN apt-get update && \
    apt-get install -y qtmultimedia5-dev
RUN apt-get install qtcreator -y
RUN apt-get install build-essential -y 
RUN apt install qtbase5-dev qt5-qmake -y

COPY . /usr/src/Catan
WORKDIR /usr/src/Catan

RUN qmake
RUN make

