
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

def bst_check_iter(T1, T2):
	stack1 = [T1]
	stack2 = [T2]
	while (len(stack1) > 0):
		node1 = stack1.pop()
		node2 = stack2.pop()
		if (node1.value != node2.value):
			return False
		elif ((node1.left == None) != (node2.left == None)):
			return False
		elif ((node1.right == None) != (node2.right == None)):
			return False 
		else:
			if (node1.right != None):
				stack1.append(node1.right)
				stack2.append(node2.right)
			if (node1.left != None):
				stack1.append(node1.left)
				stack2.append(node2.left)
	return True
