import unittest
from find import Finder

class TestFinder(unittest.TestCase):

	def test_it_should_find_pairs_with_sum(self):
		input = [8, 7, 2, 5, 3, 1]
		finder = Finder()

		output = finder.naive(input, 10)
		output_sorted = [sorted(pair) for pair in output]
		self.assertEqual(len(output), 2)
		self.assertTrue([2,8] in output_sorted)
		self.assertTrue([3,7] in output_sorted)

		output = finder.sorting(input, 10)
		output_sorted = [sorted(pair) for pair in output]
		self.assertEqual(len(output), 2)
		self.assertTrue([2,8] in output_sorted)
		self.assertTrue([3,7] in output_sorted)

		output = finder.hashing(input, 10)
		output_sorted = [sorted(pair) for pair in output]
		self.assertEqual(len(output), 2)
		self.assertTrue([2,8] in output_sorted)
		self.assertTrue([3,7] in output_sorted)


	def test_it_should_find_nothing(self):
		input = [0, 2, 4, 6, 8, 10, 12]
		finder = Finder()

		output = finder.naive(input,  5)
		output_sorted = [sorted(pair) for pair in output]
		self.assertEqual(len(output), 0)

		output = finder.sorting(input,  5)
		output_sorted = [sorted(pair) for pair in output]
		self.assertEqual(len(output), 0)

		output = finder.hashing(input,  5)
		output_sorted = [sorted(pair) for pair in output]
		self.assertEqual(len(output), 0)
