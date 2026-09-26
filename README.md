# SOLOMON ORDERBOOK

A Limit Order Book contains prices and corresponding volumes (number of shares) which people want to buy a given stock.

* Bid side represents open offers to buy
* Ask side represents open offers to sell
* Trades are made when highest bid >= lowest ask (spread is crossed)

	* Price at which trade is executed is that of the trade already in the order book
* If a client submits a buy or sell order that cannot be filled, it gets stored in the order book
* Orders are executed at the best possible price first, and if many orders have the same price, the one that was submitted earliest is chosen

Example:

```text
Ask Price: 1622.52 | Bid Price: 1622.51 | Spread: 0.01
```

NOTE the design is inspired by the [Design A Limit Order Book](https://www.youtube.com/watch?v=nmYx6tQxtSs&t=10s)

## Getting Started

### Running Locally

#### Running Tests Locally

The project uses **CMake** to build the project and **GoogleTest** to run the tests.

##### Prerequisites

On Ubuntu/Debian, install the required dependencies:

```bash
sudo apt update
sudo apt install build-essential cmake libgtest-dev
```

##### Build the Project

From the root of the repository:

```bash
cmake -S . -B build
cmake --build build
```

This creates the build directory and compiles the `OrderBook.Core` library, the GoogleTest executable, and the `OrderBook.Console` executable.

##### Run the Tests

Run all tests using CTest:

```bash
ctest --test-dir build --output-on-failure
```

A successful run should look similar to:

```text
Test project /home/federico/repos/Solomon/build
    Start 1: TestSuiteName.TestName
1/6 Test #1: TestSuiteName.TestName .....................   Passed
    Start 2: BidStore.add_addsElement
2/6 Test #2: BidStore.add_addsElement ...................   Passed
    ...
100% tests passed, 0 tests failed out of 6
```

##### Run GoogleTest Directly

You can also run the test executable directly:

```bash
./build/OrderBook.Core.Test/OrderBook.Core.Test
```

This provides the full GoogleTest output, including the individual test suites and test cases.

#### Running the Order Book Console

The project includes a console application that continuously generates random orders and submits them to the order book.

The console uses:

* A fixed ticker: `GOOG`
* Random order IDs
* Random prices
* Random buy/sell sides
* Random volumes
* Random clients
* The `Book` to store and match orders
* The `VolumeStore` to track order IDs

##### Build the Console

If you have already built the project using:

```bash
cmake -S . -B build
cmake --build build
```

the console executable will already be available.

If the project has not been built yet, run:

```bash
cmake -S . -B build
cmake --build build
```

##### Run the Console

From the root of the repository:

```bash
./build/OrderBook.Console/OrderBook.Console
```

The application will start generating and processing orders continuously.

You should see output similar to:

```text
Hello Solomon Console

...
```

A new order is generated approximately every second. Each order is added to the order book and the book attempts to match available buy and sell orders.

##### Stop the Console

The console application runs continuously using a `while (true)` loop.

To stop it, press:

```text
Ctrl+C
```

##### Running the Console with CLion

The console can also be run directly from **CLion**.

After opening the project and reloading the CMake configuration, select:

```text
OrderBook.Console
```

as the run configuration.

Then click the green **Run ▶** button.

The application will continuously generate orders until it is stopped using the **Stop** button in CLion.

##### Rebuild from Scratch

If you change the CMake configuration or encounter stale build files, remove the build directory and configure the project again:

```bash
rm -rf build
cmake -S . -B build
cmake --build build
```

After rebuilding, you can run the tests:

```bash
ctest --test-dir build --output-on-failure
```

or start the console:

```bash
./build/OrderBook.Console/OrderBook.Console
```

##### Running Tests with CLion

The project can also be opened directly in **CLion**.

CLion uses the CMake configuration in the repository to discover the targets and GoogleTests. After opening the project, reload the CMake project if necessary.

The test target is:

```text
OrderBook.Core.Test
```

CLion should automatically discover the individual GoogleTests, allowing you to run:

* All tests
* An individual test suite
* An individual test

directly from the IDE using the green **Run ▶** icons.

### Running with Docker

Docker can be used to build and run the project without installing the project dependencies locally.

#### Build the Docker Image

From the root of the repository:

```bash
docker build -t solomon .
```

#### Run the Console

```bash
docker run --rm solomon
```

The console will continuously generate and process random orders.

Press:

```text
Ctrl+C
```

to stop the container.

#### Run the Tests

Build the Docker image with the test target enabled:

```bash
docker build --build-arg BUILD_TESTING=ON -t solomon-tests .
```

Then run the tests:

```bash
docker run --rm solomon-tests \
    ctest --test-dir /build --output-on-failure
```

This runs the GoogleTest suite inside the Docker container.

## Code

### Structure

Check out the structure of the solution in this visualizer:

[readmecodegen visualizer](https://www.readmecodegen.com/file-tree/github-file-tree-visualizer)

or open it in VSCode from the Browser with the dot (`.`) button of your keyboard from the code section of GitHub.

### Data Structure for Limit Order

The data structure we implement for the process of submitting a buy order should be:

1. Check the lowest price of the sell side of the limit book
2. If the lowest price of the sell side is less than or equal to the buy side, execute a trade
3. If the buyer still has more volume left to fill, look at the next lowest price on the sell side and keep going
4. If there is unfilled volume for the buyer's trade, add it to the buyer heap

The data structure that is ideal for performing these operations is a Heap.

It is O(log n) to insert and pop where n is the number of nodes in the heap.

Use a min heap to represent the sell side and a max heap to represent the buy side.

In particular, we want to have a heap of queues to take into account that, given equal prices, the order that was filled came earlier.

### Getting Volume

We don't want to modify the state of an Order object except when it's removed for internal logic reasons.

We need to be able to get the volume, but it's important that this call happens as fast as possible.

With a vector we would have to loop through every element of a queue to sum up its volume.

But what if we kept a hashmap that kept track of the volume at each price, and incremented/decremented the volume counter when orders were added and cancelled from the limit book?

Then we would have O(1) time complexity for returning volume.

The hashmap is going to take a tuple-like structure as a key that contains the price, side, and volume as value of hashmap.

Whenever we have a new order we can increment the volume in the hashmap for a given price and side.

Instead, if we have to delete an order from the order book, we just decrement the value for the key.

#### Cancellation

There are two possible ways to cancel an order:

1. Active
2. Lazy

##### Active

Actually removing the order from the limit book:

1. Adds extra time complexity incurred by actively removing nodes from our queue and heap
2. A node is removed from the heap if the queue is empty, representing that the price of that queue is no longer at the head
3. Queue time complexity can be mitigated if we use a doubly linked list hashmap so that we can get the order node and remove it from the linked list in O(1) time

##### Lazy

Lazily mark an order as cancelled, and if we come upon it while trying to execute a trade, we skip over the cancelled order.

1. If there are many cancellations, we may have to skip a lot of potential orders because they were cancelled when trying to fill a new order
2. If we are not removing nodes from the head actively, there will be more nodes in the heap, and adding and removing nodes from the heap will take longer as a result.
