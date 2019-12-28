import unittest

from Myrange import myrange
from Myrange import MyRange

class TestMyModule(unittest.TestCase):
    
    def test_my_range_reverse(self): 
    	for i in myrange(10,0,-1):
    		pass
        
    	self.assertEqual(i,1)

    
    def test_my_range(self): 
    	for i in myrange(0,100,5):
    		pass
        
    	self.assertEqual(i,95)

    def test_MyRange_class_len(self): 
    	A=MyRange(0,10,4)

    	self.assertEqual(len(A.data),3)

    def test_MyRange_class(self): 
    	A=MyRange(0,10,3)

    	self.assertEqual(A[0],0)
    	self.assertEqual(A[1],3)
    	self.assertEqual(A[2],6)
    	self.assertEqual(A[-1],9)

if __name__ == '__main__':
    unittest.main()
