# Homework 4: Streams

develop a mechanism that allows text to be encrypted while it is being written, and it will appear when it is read.

The task is to implement the EncryptorWriter and DecryptorReader classes which allow encrypted writing of text to
any type of media, as well as reading of any type

EncryptorWriter - receives a fixed key cycle in the constructor. Instead of writing the character c, 
it converts it to an int, adds to it the value of the next character in the string obtained in the constructor,
converts the resulting amount back to char, and writes it. The transition over the constant string is circular.

DecryptorReader – does the opposite of EncryptorWriter
