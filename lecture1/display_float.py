#make sure you install ctypes : sudo apt-get install python-ctypeslib 

import ctypes
print(bin(ctypes.c_uint.from_buffer(ctypes.c_float(1.0)).value)[2:])
print(bin(ctypes.c_uint.from_buffer(ctypes.c_float(1.5)).value)[2:])
print(bin(ctypes.c_uint.from_buffer(ctypes.c_float(2.5)).value)[2:])
