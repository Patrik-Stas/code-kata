class Finder(object):
	def __init__(self):
		pass

	def naive(self, input, sum):
		n = len(input)
		out = []
		for i in xrange(n-1):
			for j in xrange(i+1,n):
				if (input[i] + input[j] == sum):
					out.append([input[i], input[j]])
		return out

	def sorting(self, input, sum):
		out = []
		input.sort()
		n = len(input)
		bp = 0 
		tp = n - 1
		while (bp < tp):
			pair_sum = input[bp] + input[tp]
			if ( pair_sum == sum):
				out.append([input[bp], input[tp]])
				bp+=1
				tp-=1
			elif (pair_sum < sum):
				bp+=1
			else:
				tp-=1
		return out


	def hashing(self, input, sum):
		out = []
		dict = {}
		for v in input:
			pair_number = sum - v
			if pair_number in dict:
				out.append([v, pair_number])
			else:
				dict[v] = v
		return out
