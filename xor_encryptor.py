#!/usr/bin/env python3
import sys

# key should be similar to the one in the C++ file(main.cpp). Please
# endeavour to change it!!
KEY = "password"


def xor(plain_input, xor_key):
    xor_key = str(xor_key)
    key_length = len(xor_key)

    xor_data = ""
    i = 0
    # Looping over byte strings produces the characters' ASCII value 
    # in base ten(decimal) unlike strings.
    for char in plain_input:
        xor_data += chr(char ^ ord(xor_key[i % key_length]))
        i += 1

    return xor_data


def printCiphertext(ciphertext):
    print('{ 0x' + ', 0x'.join(hex(ord(x))[2:] for x in ciphertext) + ' };')


def main():
    try:
        with open(sys.argv[1], "rb") as fp:
            plaintext = fp.read()
    except IndexError:
        print("[-] File argument needed! %s " % sys.argv[0])
        sys.exit(1)
    except Exception as e:
        print(f"[-] Error with specified file({sys.argv[1]}): {e}")
        sys.exit(1)
    else:
        ciphertext = xor(plaintext, KEY)
        printCiphertext(ciphertext)
        return


if __name__ == '__main__':
    main()
