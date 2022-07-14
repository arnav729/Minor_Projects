import re
def passwd():
    while True:
        password=input("Enter a password ")
        if len(password)<8:
            print("Password must be at least 8 characters")
        elif re.search('[0123456789]',password) is None:
            print("Must contain an integer")
        elif re.search('[ABCDEFGHIJKLMNOPQRSTUVWXYZ]',password) is None:
            print("Must contain a capital alphabet")
        elif re.search('[abcdefghijklmnopqrstuvwxyz]',password) is None:
            print("Must contain a small alphabet")    
        elif re.search('[~!@#$%^&*()_+/*-<>]',password) is None:
            print("Must contain a special character")
        else:
            print("Password is strong!!")
            break
passwd()            
