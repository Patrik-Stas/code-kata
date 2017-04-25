
class Node(object):
	def __init__(self, left, right, value):
		self.left = left
		self.right = right
		self.value = value

def bst_check_rec(T1, T2):
	if (T1 == None and T2 == None):
		return True
	
	if (T1.value != T2.value):
		return False
	elif ((T1.left == None) != (T2.left == None)):
		return False
	elif ((T1.right == None) != (T2.right == None)):
		return False 
	else:
		return bst_check_rec(T1.left, T2.left) and bst_check_rec(T1.right, T2.right)
	