# SOLOMON ORDERBOOK

A Limit Order Book contains prices and corresponding volumnes (number of shares) which people want to buy a given stock.
- Bid side represents open offest to buy
- Ask side represent open offers to sell
- Trades are made when highest bid >= lowest ask (spread is crossed)
	Price at which trade is executed is that of the trade already in the order book
- Ifd client submits a buy or sell order that cannot be filled, iot gest stored in order bok
- Orders are executed at the best possible price fist, and if many orders have the same price the one that was submitted
earliest is chosen

Example
Ask Price: 1622.52 | Bid Price: 1622.51 | Spread: 0.01

NOTE the design is inspired by the [Design A Limit Order Book](https://www.youtube.com/watch?v=nmYx6tQxtSs&t=10s)

## Data Structure for Limit Order
The data structure we implement for the process of submitting a buy order should be:
1. Check the lowest price of the sell side of the limit book
2. If the lowest price of the sell side is less than or equal to the buy side, the execute a trade
3. If the buyer still has more volume left to fill, look at the next lowest price on the sell side and keep going
4. If the is unfilled volume for the buyer's trad, add it to the buyer heap.

The data structure that is ideal for performing these operations in a Heap.
It is O(logn) to insert and pops where n is the number of nodes in the heap.
Use min heap to represent sell side and max heap to represent buy side.

In particular we want to have a heap of queues to take into account that, given equal prices, if filled the order
that came earlier.

## Getting Volume
We don't want to modify the state of an Order object except when it's removed for internal logic reasons.

We need to be able to get the volume, but it's important that this call happens as fast as possible.
With a vector we would have to loop through every element of a queue to sum up it's volume.
But what if we kept a hashmap that kept track of the volume at each price, and incremented/decremented the volume
counter when order were added and cancelled from the limit book?

Then we would have O(1) time complexity for returning volume.

The hashmap is goin to take a tuple like structure as a key that contains the price side and volume as value of hashmap.
Whenever we have a new order we can increment the volume in the hashmap for a given price and side.
Insted if we have to delete an order form the order book we just decrement the value for the key.

### Cancellation
There are two possible ways to cancel an order
1. Active
2. Lazy

#### Active
Actually removing the order from the limit book
1. Add extra time complexity incurred by actively removing nodes from our queue and head
2. Node removed from heap if queue is empty, representing that trhe price of that queue is in longer in the head
3. Queue time coplexity can be egated if we use a doubly linked list hashmap so tha we can get the order node 
and remove it from the linked list in O(1) time

#### Lazy 
Lazily mark order as cancelled, and if we come upon it thile trying to execute a trade we skip over the cancelled order.
1. If there are many cancvellations, we may have to skip a lot of potential orders (b/c tgey were cancelled)
when trying to fill a new order
2. If we are not removing nodes from the head actively, there will be more nodes in the heap and adding and removing
nodes from the heap will take longer as a result


## Structure
The project is organized with the following Directory structure:

└── federicopessina-Solomon/<br/>
    ├── README.md<br/>
    ├── CMakeLists.txt<br/>
    ├── CMakePresets.json<br/>
    ├── OrderBook.Console/<br/>
    │   ├── CMakeLists.txt<br/>
    │   ├── OrderBook.Console.cpp<br/>
    │   └── OrderBook.Console.h<br/>
    ├── OrderBook.Core/<br/>
    │   ├── AskStore.cpp<br/>
    │   ├── AskStore.h<br/>
    │   ├── BidStore.cpp<br/>
    │   ├── BidStore.h<br/>
    │   ├── Book.cpp<br/>
    │   ├── Book.h<br/>
    │   ├── BookConsole.cpp<br/>
    │   ├── BookConsole.h<br/>
    │   ├── CMakeLists.txt<br/>
    │   ├── IVolumeMap.h<br/>
    │   ├── Order.cpp<br/>
    │   ├── Order.h<br/>
    │   ├── OrderBook.Core.cpp<br/>
    │   ├── OrderBook.Core.h<br/>
    │   ├── OrderConsole.cpp<br/>
    │   ├── OrderConsole.h<br/>
    │   ├── VolumeStore.cpp<br/>
    │   ├── VolumeStore.h<br/>
    │   └── Exceptions/<br/>
    │       ├── Store.Exception.cpp<br/>
    │       └── Store.Exception.h<br/>
    └── OrderBook.Core.Test/<br/>
        ├── OrderBook.Core.Test.vcxproj<br/>
        ├── packages.config<br/>
        ├── pch.cpp<br/>
        ├── pch.h<br/>
        └── test.cpp<br/>


