#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Your data structure should implement two methods

addWord(word) - Adds word to the data structure

search(word) - Returns true if there is any string in the data structure that matches word. word may contain dots where a dot can be matched with any letter
"""
__author__ = "prakashsellathurai"
__copyright__ = "Copyright 2021"
__version__ = "1.0.1"
__email__ = "prakashsellathurai@gmail.com"

class TrieNode(object):
    """docstring for TrieNode."""
    def __init__(self, val=None):
        super(TrieNode, self).__init__()
        self.val = val
        self.children = {}
        self.isEnd = False

class WordDictionary(object):
    """docstring for WordDictionary.
    
    >>> wordDictionary =  WordDictionary()
    >>> wordDictionary.addWord("bad");
    >>> wordDictionary.addWord("dad");
    >>> wordDictionary.addWord("mad");
    >>> wordDictionary.search("pad")
    False
    >>> wordDictionary.search("bad")
    True
    >>> wordDictionary.search(".ad")
    True
    >>> wordDictionary.search("b..")
    True
    """
    def __init__(self):
        super(WordDictionary, self).__init__()
        self.root = TrieNode()
    
    def addWord(self,word:str) -> None:
        """adds a word into the data structure

        Args:
            word (str)
        """
        cur = self.root
        for l in word:
            if l not in cur.children:
                cur.children[l] = TrieNode(l)
            cur = cur.children[l]
        cur.isEnd = True
        
    def search(self,word: str) -> bool:
        """
        Returns if the word is in data structure
        A word contain the dot character '.' to represent any one letter

        Args:
            word (str): 

        Returns:
            bool: 

        """
        def _search(root,index):
            if index == len(word):
                return root.isEnd == True
            else:
                if word[index] == '.':
                    for l,child in root.children.items():
                        if _search(child,index+1):
                            return True
                else:
                    if word[index] in root.children:
                        root = root.children[word[index]]
                        return _search(root,index+1)
                return False
        return _search(self.root,0)
    
if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True)