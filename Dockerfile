FROM gcc:latest

RUN mkdir /tron
COPY . /tron

WORKDIR /tron

RUN make clean
RUN make final

ENTRYPOINT ["./final"]
