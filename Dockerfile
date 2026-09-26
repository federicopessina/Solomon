# ---------- Build stage ----------
FROM gcc:14 AS builder

# Install CMake and Ninja
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        cmake \
        ninja-build \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src

# Copy the project source
COPY . .

# Configure
RUN cmake \
    -S . \
    -B /build \
    -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_STANDARD=20 \
    -DBUILD_TESTING=OFF

# Build only the console application
RUN cmake --build /build --target OrderBook.Console --parallel


# ---------- Runtime stage ----------
FROM debian:trixie-slim AS runtime

WORKDIR /app

# Copy the executable from the build stage
COPY --from=builder /build/OrderBook.Console/OrderBook.Console /app/OrderBook.Console

ENTRYPOINT ["/app/OrderBook.Console"]
