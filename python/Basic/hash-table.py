class HashTable:
    def __init__(self, size=None):
        self.dict = {}
        self.size = size

    def add(self, key, value):
        self.dict[key] = value
        self.size = 1 if (self.size is None) else self.size + 1

    def exists(self, key):
        try:
            return self.dict[key] is not None
        except:
            return False

    def get(self, key):
        try:
            return self.dict[key]
        except:
            return "Not Found"

    def remove(self, key):
        del self.dict[key]

    def print(self):
        print("contents")
        for x in self.dict:
            print("key : ", x, " val: ", self.dict[x])


if __name__ == "__main__":
    hash = HashTable()
    hash.add(23, [333, 33])
    hash.add("eeee", 4444)
    print(hash.exists("eee"))
    print(hash.exists("eeee"))
    print(hash.get(23))
    print(hash.get(2))
    hash.print()
    hash.remove(23)
    hash.print()

    # Function to display hashtable
    def display_hash(hashTable):

        for i in range(len(hashTable)):
            print(i, end=" ")

            for j in hashTable[i]:
                print("-->", end=" ")
                print(j, end=" ")

            print()

    # Creating Hashtable as
    # a nested list.
    HashTable = [[] for _ in range(10)]

    # Hashing Function to return
    # key for every value.
    def Hashing(keyvalue):
        return keyvalue % len(HashTable)

    # Insert Function to add
    # values to the hash table
    def insert(Hashtable, keyvalue, value):

        hash_key = Hashing(keyvalue)
        Hashtable[hash_key].append(value)

    # Driver Code
    insert(HashTable, 10, "Allahabad")
    insert(HashTable, 25, "Mumbai")
    insert(HashTable, 20, "Mathura")
    insert(HashTable, 9, "Delhi")
    insert(HashTable, 21, "Punjab")
    insert(HashTable, 21, "Noida")

    display_hash(HashTable)
