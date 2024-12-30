FROM debian:bookworm AS builder

WORKDIR /build

RUN apt-get update && apt-get install -y emscripten make

COPY . .

RUN make
RUN mkdir /web
RUN cp so_long.data /web
RUN cp so_long.html /web/index.html
RUN cp so_long.js /web
RUN cp so_long.wasm /web

FROM afonsopc/web-server AS runtime

COPY --from=builder /web/ /web/