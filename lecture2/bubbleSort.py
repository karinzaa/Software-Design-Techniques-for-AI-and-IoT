def bbsort(alist):
	for i in range (0,len(alist)) :
		for  j in range (1, len(alist) - i) :
			if (alist[j-1] > alist[j]) :
				print("n = %s : i = %s : j =%s : n-i = %s" %(len(alist),i,j ,(len(alist)-i)))
				temp = alist[j]
				alist[j] = alist[j-1]
				alist[j-1] = temp
	return (alist)

a = [10,5,3,4,2,16,9,8,1,0]
print("Before Sorting: ")
print(a)
tmp = a
a = bbsort(a)
print("After Sorted: ")
print(a)
print("Using .Sort Method")
tmp.sort()
print(tmp)
tmp.sort(reverse=True)
print(tmp)