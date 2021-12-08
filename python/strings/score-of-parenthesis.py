

def scoreOfParentheses(s: str) -> int:
    ans  = bal = 0
    
    for i,x in enumerate(s):
        if x == '(':
            bal += 1
        else:
            bal -= 1
            if s[i-1] == '(':
                ans += (1<<bal)
    return ans



import unittest

class TestStringMethods(unittest.TestCase):

    def test_all_cases(self):
        self.assertEqual(scoreOfParentheses("()"), 1)
        self.assertEqual(scoreOfParentheses("(())"), 2)
        self.assertEqual(scoreOfParentheses("()()"), 2)
        self.assertEqual(scoreOfParentheses("(()(()))"), 6)

if __name__ == '__main__':
    unittest.main()
