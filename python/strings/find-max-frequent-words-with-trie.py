class Trie:
    def __init__(self, parent=None):
        self.parent = parent
        self.children = {}
        self.n = 0

    def add(self, c):
        return self.children.setdefault(c, Trie(self))

    def letter(self, child):
        for c in self.children:
            if self.children[c] == child:
                return c
        return None

    def spell(self):
        if self.parent:
            return self.parent.spell() + self.parent.letter(self)
        return ""


def wrap(text):
    """iterates through text, yielding lowercase letter or single ' '"""
    inword = False
    for c in text:
        if str(c).isalpha():
            yield c
            inword = True
        else:
            if inword:
                yield " "
            inword = False
    if inword:
        yield " "


def pairmax(text):
    """finds the word pair with maximum occurrence"""
    root = word2 = Trie()
    word1 = None
    best = Trie()
    for c in wrap(text):
        if c == " ":
            if word1:
                word2.n += 1

                word2 = word1.add(" ")
                word1 = root
            else:
                word1 = root
                word2 = word2.add(" ")
        else:
            word2 = word2.add(c)
            if word2.n > best.n:
                best = word2
            if word1:
                word1 = word1.add(c)
        print(word2.n)
        if word2.n > best.n:
            best = word2

    return best.spell(), best.n


if __name__ == "__main__":
    from urllib.request import urlopen
    import sys

    urls = ["http://www.rfc-editor.org/rfc/rfc19%02d.txt" %
            i for i in range(30, 40)]

    for url in urls:
        word, n = pairmax(urlopen(url).read())
        sys.stdout.write('%s : %dx "%s"\n' % (url, n, word))
