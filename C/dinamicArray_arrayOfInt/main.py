import ctypes
import time

lib = ctypes.CDLL('./dinamicArray.dll')

# Define C struct for Python
class ArrayOfInt(ctypes.Structure):
    _fields_ = [
        ("list", ctypes.POINTER(ctypes.c_int)),
        ("length", ctypes.c_int)
    ]

lib.createArrayOfInt.restype = ctypes.POINTER(ArrayOfInt)
lib.displayArray.argtypes = [ctypes.POINTER(ArrayOfInt)]
lib.addElementToArray.argtypes = [ctypes.POINTER(ArrayOfInt), ctypes.c_int]

# In C
array = lib.createArrayOfInt()
start_c = time.time()
lib.addElementToArray(array, 10)
lib.addElementToArray(array,11)
end_c = time.time()

# In Python
a = []
start_py = time.time()
a.append(10)
a.append(11)
end_py = time.time()

array_in_python = array.contents.list[:array.contents.length]
print("Array:", str(array_in_python) + ".")

print("Add elements in C:", end_c - start_c)
print("Add elements in Python:", end_py - start_py)