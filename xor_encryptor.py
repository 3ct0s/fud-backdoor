#!/usr/bin/env python3
import sys


class XorCipher:
    __slots__ = ("key", "_key_length", "_fname", "_ciphertext", "_plaintext")

    def __init__(self, filename: str, xor_key="password") -> None:
        self.key = str(xor_key)
        self._key_length = len(self.key)
        self._fname = filename
        self._ciphertext = ""
        self._plaintext = b""

    def _xor_crypt(self) -> None:
        i = 0
        # Looping over byte strings produces the characters' ASCII value
        # in base ten(decimal) unlike strings.
        for char in self._plaintext:
            self._ciphertext += chr(char ^ ord(self.key[i % self._key_length]))
            i += 1

    def _print_ciphertext(self) -> None:
        from textwrap import TextWrapper

        wrapper = TextWrapper(width=56, initial_indent="\n")
        xor_array = (
            "{ 0x" + ", 0x".join(hex(ord(x))[2:] for x in self._ciphertext) + " };"
        )
        wrapped_xor_array = wrapper.fill(xor_array)
        print(wrapped_xor_array)

    def run(self) -> None:
        try:
            with open(self._fname, "rb") as fp:
                self._plaintext = fp.read()
        except Exception as e:
            print(f"[-] Error with specified file({self._fname}): {e}")
            sys.exit(1)
        else:
            self._xor_crypt()
            self._print_ciphertext()
            return


if __name__ == "__main__":
    # xor key should be similar to the one in the C++ file(main.cpp). Please
    # endeavour to change it!!(BY DEFAULT WE'VE SET IT TO "password" WHICH MAY
    # NOT BE THE BEST PASSWORD/KEY BUT FIT FOR A DEMO)
    # Also the "file" opened by default is the file you supply at the command line
    # NOTE: You can port this class to your own scripts neatly.
    try:
        file_name = sys.argv[1]
        xor_crypt = XorCipher(file_name)
    except IndexError:
        print("[-] File argument needed! \n\t%s <file_to_xor_encrypt>" % sys.argv[0])
        sys.exit(1)
    else:
        xor_crypt.run()
