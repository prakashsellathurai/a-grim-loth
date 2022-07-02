import threading

def printFizz():
    print("Fizz")

def printBuzz():
    print("Buzz")

def printFizzBuzz():
    print("FizzBuzz")

def printNumber(i):
    print(i)

class MultithreadedFizzBuzz:
    def __init__(self, n):
        self.__n = n
        self.__curr = 0
        self.__cv = threading.Condition()

    # printFizz() outputs "fizz"
    def fizz(self, printFizz):
        """
        :type printFizz: method
        :rtype: void
        """
        for i in range(1, self.__n+1):
            with self.__cv:
                while self.__curr % 4 != 0:
                    self.__cv.wait()
                self.__curr += 1
                if i % 3 == 0 and i % 5 != 0:
                    printFizz()
                self.__cv.notify_all()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz):
        """
        :type printBuzz: method
        :rtype: void
        """
        for i in range(1, self.__n+1):
            with self.__cv:
                while self.__curr % 4 != 1:
                    self.__cv.wait()
                self.__curr += 1
                if i % 3 != 0 and i % 5 == 0:
                    printBuzz()
                self.__cv.notify_all()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz):
        """
        :type printFizzBuzz: method
        :rtype: void
        """
        for i in range(1, self.__n+1):
            with self.__cv:
                while self.__curr % 4 != 2:
                    self.__cv.wait()
                self.__curr += 1
                if i % 3 == 0 and i % 5 == 0:
                    printFizzBuzz()
                self.__cv.notify_all()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in range(1, self.__n+1):
            with self.__cv:
                while self.__curr % 4 != 3:
                    self.__cv.wait()
                self.__curr += 1
                if i % 3 != 0 and i % 5 != 0:
                    printNumber(i)
                self.__cv.notify_all()

fb = MultithreadedFizzBuzz(100)

thread1 = threading.Thread(target=fb.fizz, args=(printFizz,))
thread2 = threading.Thread(target=fb.buzz, args=(printBuzz,))
thread3 = threading.Thread(target=fb.fizzbuzz, args=(printFizzBuzz,))
thread4 = threading.Thread(target=fb.number, args=(printNumber,))



thread1.start()
thread2.start()
thread3.start()
thread4.start()

thread1.join()
thread2.join()
thread3.join()
thread4.join()
