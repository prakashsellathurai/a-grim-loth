class SuffixNode:
    def __init__(self, suffix_link = None):
        self.children = {}
        if suffix_link is not None:
            self.suffix_link = suffix_link
        else:
            self.suffix_link = self
    def add_link(self, c, v):
        """link this node to node v via string c"""
        self.children[c] = v
        
def build_suffix_trie(s):
    """Construct a suffix trie."""
    assert len(s) > 0
    # explicitly build the two-node suffix tree
    Root = SuffixNode() # the root node
    Longest = SuffixNode(suffix_link = Root)
    Root.add_link(s[0], Longest)

    # for every character left in the string
    for c in s[1:]:
        Current = Longest; Previous = None
        while c not in Current.children:
            # create new node r1 with transition Current -c->r1
            r1 = SuffixNode()
            Current.add_link(c, r1)
            # if we came from some previous node, make that
            # node's suffix link point here
            if Previous is not None:
                Previous.suffix_link = r1
            # walk down the suffix links
            Previous = r1
            Current = Current.suffix_link
            # make the last suffix link
        if Current is Root:
            Previous.suffix_link = Root
        else:
            Previous.suffix_link = Current.children[c]
        # move to the newly added child of the longest path
        # (which is the new longest path)
        Longest = Longest.children[c]
    return Root    
if __name__ == "__main__":
    s = "ab"
    suffixTrie = build_suffix_trie(s)

    