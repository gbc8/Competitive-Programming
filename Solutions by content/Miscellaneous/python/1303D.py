import heapq

for _ in range(int(input())):
	n, m = map(int, input().split())
	h = list(map(int,input().split()))	
	for j in range(m):
		h[j] *= -1
	heapq.heapify(h)
	ans = 0
	s = -sum(h)
	if(s < n):
		print(-1)
		continue
	while n > 0:
		x = -heapq.heappop(h)
		if x <= n:
			n -= x
			s -= x
		elif s-x < n:
			heapq.heappush(h,-x/2)
			heapq.heappush(h,-x/2)
			ans += 1
		else:
			s -= x
	print(ans)
