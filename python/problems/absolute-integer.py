
# For 32 bit it will return 32 and for 64 bit it will return 64
import struct

def get_sys_bit_mode():
    return struct.calcsize("P") * 8
    
def absolute_integer(num):
    bit_mode = num >> (get_sys_bit_mode()-1)
    return (num^bit_mode) - bit_mode

if __name__ == "__main__":
    print(absolute_integer(23))
    print(absolute_integer(-23))