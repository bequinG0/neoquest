import random
import time
# NQ2024

def encoding(string, key):
    str_encode = ""
    for i in range(0, len(string), 6):
        block = string[i:i+6]
        encode_block = ""
        for j in range(len(block)):
            temp = ord(block[j]) ^ key[j]
            encode_block += chr(temp)
        str_encode += encode_block
    return str_encode.encode()

def getkey():
    random.seed(int(time.time()))
    key = []
    for i in range(0, 6):
        temp = random.randint(0, 256)
        key.append(temp)
    return key

print("[*] Hey guys! This is cipher program")
print("[*] Write the message:")
message = str(input())
if message.encode() == b'h\x13\x12]D\xc3\x84\x17q\x18\\N\xc3\x87\x1ft\x15ZB\xc3\x88\x12{\x11]G\xc3\x87\x17w\x11]O\xc3\x82\x10p\x17]C\xc3\x81\x16{\x14_G\xc3\x88\x16{':
    print("[ERORR] You want to hack me!? Nope.")
else:
    encode = encoding(message, getkey())
    print("[*] Encoding message: ", encode)
print("GLHF")



