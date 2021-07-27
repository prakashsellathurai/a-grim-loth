"""[summary]

Appropriate values for P and M 



P: The value of P can be any prime number roughly equal to the number of different characters used. 
For example: if the input string contains only lowercase letters of the English alphabet, then P = 31 is the appropriate value of P. 
If the input string contains both uppercase and lowercase letters, then P = 53 is an appropriate option.
M: the probability of two random strings colliding is inversely proportional to m, Hence m should be a large prime number. 
M = 10 ^9 + 9 is a good choice.
"""


def hash(text):
    # P and M
    p = 31
    m = 1e9 + 9
    power_of_p = 1
    hash_val = 0

    # Loop to calculate the hash value
    # by iterating over the elements of string
    for i in range(len(text)):
        hash_val = (hash_val + (ord(text[i]) - ord("a") + 1) * power_of_p) % m

        power_of_p = (power_of_p * p) % m

    return int(hash_val)


if __name__ == "__main__":
    text = "djdbgjgjgfsngbd"

    print(hash(text))
