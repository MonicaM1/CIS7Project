# CIS7Project

This program encrypts and decrypts alphabetical messages using a Vigenere cipher, given a message and a key.

Uppercase and lowercase Vigenere tables are generated using nested for loops and two-dimensional arrays.
These arrays are populated using modulo operations on ASCII values corresponding to alphabetic characters.
The user-input key is resized to match the length of the user's message.

Encryption is accomplished by mapping message characters to rows in the table and key characters to columns, each indexed 0-25.
The new, encrypted letter is found in the table by intersecting the column with the row.

Decryption is accomplished by mapping key character to columns, indexed 0-25.
The row containing the key character is searched, until the index containing the message character is found.
The new, decrypted letter is found in the table by intersecting that index as the row with zero as the column.

Encrypted or decrypted letters are added to an output string, which is then printed.

Author: Monica Michael

Date Published: December 14th, 2022

Basic Instructions For Users:
Following the prompts given, input 1 to encrypt a message or 2 to decrypt a message.
Enter an alphabetical message without spaces, then an alphabetical key without spaces.
The program will output the encrypted or decrypted message.
