class Queue:
    def __init__(self, limit=10):
        self.queue = []
        self.front = None
        self.rear = None
        self.limit = limit
        self.size = 0

    def __str__(self):
        return " ".join([str(i) for i in self.queue])

    # to check if queue is empty
    def isEmpty(self):
        return self.size <= 0

    # to add an element from the rear end of the queue
    def enqueue(self, data):
        if self.size >= self.limit:
            return -1  # queue overflow
        self.queue.append(data)

        # assign the rear as size of the queue and front as 0
        if self.front is None:
            self.front = self.rear = 0
        else:
            self.rear = self.size

        self.size += 1

    # to pop an element from the front end of the queue
    def dequeue(self):
        if self.isEmpty():
            return -1  # queue underflow
        self.queue.pop()
        self.size -= 1
        if self.size == 0:
            self.front = self.rear = 0
        else:
            self.rear = self.size - 1

    def getSize(self):
        return self.size


myQueue = Queue()
for i in range(10):
    myQueue.enqueue(i)
print(myQueue)
print("Queue Size:", myQueue.getSize())
myQueue.dequeue()
print(myQueue)
print("Queue Size:", myQueue.getSize())
