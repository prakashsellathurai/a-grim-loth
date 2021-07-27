# Python3 implementation to break
# a sequence into the words of
# the dictionary

# Unordered_map used for storing
# the sentences the key string
# can be broken into
mp = dict()

# Unordered_set used
# to store the dictionary.
dict_t = set()

# Utility funtion used for
# printing the obtained result


def printResult(A):

    for i in range(len(A)):
        print(A[i])


# Utility function for
# appending new words
# to already existing strings
def combine(prev, word):

    # Loop to find the append string
    # which can be broken into
    for i in range(len(prev)):

        prev[i] += " " + word

    return prev


# Utility funtion for word Break
def wordBreakUtil(s):

    # Condition to check if the
    # subproblem is already computed
    if s in mp:
        return mp[s]

    res = []

    # If the whole word is a dictionary
    # word then directly append into
    # the result array for the string
    if s in dict_t:
        res.append(s)

    # Loop to iterate over the substring
    for i in range(1, len(s)):

        word = s[i:]

        # If the substring is present into
        # the dictionary then recurse for
        # other substring of the string
        if word in dict_t:

            rem = s[:i]
            prev = combine(wordBreakUtil(rem), word)
            for i in prev:
                res.append(i)

    # Store the subproblem
    # into the map
    mp[s] = res
    return res


# Master wordBreak function converts
# the string vector to unordered_set
def wordBreak(s, wordDict):

    # Clear the previous stored data
    mp.clear()
    dict_t.clear()
    for i in wordDict:
        dict_t.add(i)
    return wordBreakUtil(s)


# Driver Code
if __name__ == "__main__":

    wordDict1 = ["cat", "cats", "and", "sand", "dog"]
    printResult(wordBreak("catsanddog", wordDict1))
