import ctypes
from ctypes import c_char_p, c_size_t, c_double, byref, POINTER

lib = ctypes.CDLL('lib/msys-__data_analysis_emb.dll')

get_vect_nums = lib.get_vect_nums
get_vect_nums.argtypes = [c_char_p, c_size_t]
get_vect_nums.restype = POINTER(c_double)

delete_vect_nums = lib.delete_vect_nums
delete_vect_nums.argtypes = [POINTER(c_double)]
delete_vect_nums.restype = None