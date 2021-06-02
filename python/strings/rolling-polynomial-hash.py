import math
def compute_hash(String):
    p = 31
    m = (math.e**9) + 9
    hash_value = 0
    p_pow = 1
    for c in String:
        hash_value = (hash_value+ (ord(c)-ord('a')+1)*p_pow) %m
        p_pow = (p*p_pow) %m
    return int(hash_value)


if __name__ == "__main__":
        
    String = "dfbehbehfbeh"

    print(compute_hash(String))