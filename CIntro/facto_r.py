def facto_r(n):
	if n==0 or n==1:
		return 1
	else:
		return n*facto_r(n-1)