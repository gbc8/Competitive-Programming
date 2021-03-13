for j in range(0,int(input())):
	n = int(input())
	l = sorted(list(map(int, input().split())))
	ans = True
	for i in range(1,len(l)):
		if(l[i]-l[i-1] > 1):
			ans = False
			break
	if ans == False:
		print("NO")
	else:
		print("YES")
