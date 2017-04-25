import unittest
from bsearch import bsearch

class TestBinarySearch(unittest.TestCase):

	def test_it_should_find_number_1_0(self):
		data = [1]
		result = bsearch(data, 1)
		self.assertEquals(0, result)

	def test_it_should_find_number_2_0(self):
		data = [3,5]
		result = bsearch(data, 3)
		self.assertEquals(0, result)

	def test_it_should_find_number_2_1(self):
		data = [3,5]
		result = bsearch(data, 5)
		self.assertEquals(1, result)

	def test_it_should_find_number_3_0(self):
		data = [3,5,6]
		result = bsearch(data, 3)
		self.assertEquals(0, result)

	def test_it_should_find_number_3_1(self):
		data = [3,5,6]
		result = bsearch(data, 5)
		self.assertEquals(1, result)

	def test_it_should_find_number_3_2(self):
		data = [3,5,6]
		result = bsearch(data, 6)
		self.assertEquals(2, result)

	def test_it_should_find_number_4_0(self):
		data = [3,5,6,10]
		result = bsearch(data, 3)
		self.assertEquals(0, result)

	def test_it_should_find_number_4_1(self):
		data = [3,5,6,10]
		result = bsearch(data, 5)
		self.assertEquals(1, result)

	def test_it_should_find_number_4_2(self):
		data = [3,5,6,10]
		result = bsearch(data, 6)
		self.assertEquals(2, result)

	def test_it_should_find_number_4_3(self):
		data = [3,5,6,10]
		result = bsearch(data, 10)
		self.assertEquals(3, result)

	def test_it_should_find_number_big(self):
		data = [3,5,6,10,13,15,16,100,300,1000,1001,1003]
		result = bsearch(data, 1001)
		self.assertEquals(10, result)

	def test_it_should_return_minus_one_if_not_found(self):
		data = [3,5,6,10,13,15,16,100,300,1000,1001,1003]
		result = bsearch(data, 222)
		self.assertEquals(-1, result)

		