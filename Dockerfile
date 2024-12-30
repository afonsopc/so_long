FROM afonsopc/web-server AS runtime

COPY so_long.js so_long.wasm so_long.data /web/
COPY so_long.html /web/index.html