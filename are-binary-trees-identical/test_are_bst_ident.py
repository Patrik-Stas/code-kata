import unittest
from are_bst_ident import Node
from are_bst_ident import bst_check_rec
from are_bst_ident import bst_check_iter

class TestBstIdentical(unittest.TestCase):

	def test_tree_should_be_identical_to_itself(self):
		RRL1 = Node(None, None, 2)
		RRR1 = Node(None, None, 5)
		RR1 = Node(RRL1, RRR1, 7)
		RL1 = Node(None, None, 14)
		R1 = Node(RL1, RR1, 64)
		LL1 = Node(None, None, 65)
		L1 = Node(LL1, None, 111)
		ROOT1 = Node(L1, R1, 1235)

		self.assertTrue(bst_check_rec(ROOT1, ROOT1))
		self.assertTrue(bst_check_iter(ROOT1, ROOT1))

	def test_it_sohuld_return_false_if_value_differs(self):
		RRL1 = Node(None, None, 2)
		RRR1 = Node(None, None, 5)
		RR1 = Node(RRL1, RRR1, 7)
		RL1 = Node(None, None, 14)
		R1 = Node(RL1, RR1, 64)
		LL1 = Node(None, None, 65)
		L1 = Node(LL1, None, 111)
		ROOT1 = Node(L1, R1, 1235)

		RRL2 = Node(None, None, 2)
		RRR2 = Node(None, None, 5)
		RR2 = Node(RRL2, RRR2, 9999999)
		RL2 = Node(None, None, 14)
		R2 = Node(RL2, RR2, 64)
		LL2 = Node(None, None, 65)
		L2 = Node(LL2, None, 111)
		ROOT2 = Node(L2, R2, 1235)

		self.assertFalse(bst_check_rec(ROOT1, ROOT2))
		self.assertFalse(bst_check_iter(ROOT1, ROOT2))

	def test_it_should_return_false_if_structure_differs(self):
		RRL1 = Node(None, None, 2)
		RRR1 = Node(None, None, 5)
		RR1 = Node(RRL1, RRR1, 7)
		RL1 = Node(None, None, 14)
		R1 = Node(RL1, RR1, 64)
		LL1 = Node(None, None, 65)
		L1 = Node(LL1, None, 111)
		ROOT1 = Node(L1, R1, 1235)

		RRR2 = Node(None, None, 5)
		RR2 = Node(None, RRR2, 7)
		RL2 = Node(None, None, 14)
		R2 = Node(RL2, RR2, 64)
		L2 = Node(None, None, 111)
		ROOT2 = Node(L2, R2, 1235)

		self.assertFalse(bst_check_rec(ROOT1, ROOT2))
		self.assertFalse(bst_check_iter(ROOT1, ROOT2))

if __name__ == '__main__':
	unittest.main()