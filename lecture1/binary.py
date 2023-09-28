

c = 100

print(bin(c))

c= -100

print(bin(c))


def create_bits(n, bits):
	s = bin(n & int("1"*bits,2))[2:]
	return ("{0:0>%s}" %(bits)).format(s)

print("  %s = %s" %(100,create_bits(100,32)))
print(" %s = %s" %(-100,create_bits(-100,32)))
