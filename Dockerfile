FROM alpine:3.14
RUN apk add --no-cache gcc make musl-dev

COPY . /srv/snake
WORKDIR /srv/snake

RUN make
