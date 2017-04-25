from math import *

def bsearch(numbers, target_value):
	top=len(numbers)-1
	bottom=0
	return __bsearch(numbers, target_value, bottom, top)

def __bsearch(numbers, target_value, bottom, top):
	if (bottom>top):
		return -1
	pivot_idx = int(floor((top + bottom)/2))
	pivot_value = numbers[pivot_idx]
	if (pivot_value==target_value):
		return pivot_idx
	elif (pivot_value<target_value):
		return __bsearch(numbers, target_value, pivot_idx+1, top)
	else:
		return __bsearch(numbers, target_value, bottom, pivot_idx-1)
