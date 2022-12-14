#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
  
  // UPPER CASE VIGENERE TABLE:
  char tableUpper [26][26];
  for (unsigned int i = 0; i < 26; i++) {
    for (unsigned int j = 0; j < 26; j++) {
      int tempVal = 'A' + i + j;
      if (tempVal > 90) {
        tempVal = 'A' + (tempVal % 90) - 1;
      }
      tableUpper[i][j] = tempVal;
    }
  }
  
/*
  // For Debugging Only, Print Upper Case Table:
  cout << "Upper Case Vigenere Table:" << endl;
  for (unsigned int i = 0; i < 26; i++) {
    for (unsigned int j = 0; j < 26; j++) {
      cout << tableUpper[i][j];
      if (j == 25) {
        cout << endl;
      }
    }
  }
  cout << endl;
*/
  
  // LOWER CASE VIGENERE TABLE:
  char tableLower [26][26];
  for (unsigned int i = 0; i < 26; i++) {
    for (unsigned int j = 0; j < 26; j++) {
      int tempVal = 'a' + i + j;
      if (tempVal > 122) {
        tempVal = 'a' + (tempVal % 122) - 1;
      }
      tableLower[i][j] = tempVal;
    }
  }
  
/*
  // For Debugging Only, Print Lower Case Table:
  cout << "Lower Case Vigenere Table:" << endl;
  for (unsigned int i = 0; i < 26; i++) {
    for (unsigned int j = 0; j < 26; j++) {
      cout << tableLower[i][j];
      if (j == 25) {
        cout << endl;
      }
    }
  }
  cout << endl;
*/
  
  // START PROMPTS FOR OPTIONS:
  cout << "Welcome. This program encrypts and decrypts messages. " << endl;
  cout << "Please enter 1 to encrypt a message, or 2 to decrypt a message:" << endl;

  string option;
  getline(cin, option);

  // INPUT VALIDATION FOR OPTIONS:
  while (option != "1" && option != "2") {
    cout << "Invalid input. " << endl;
    cout << "Please enter either 1 to encrypt a message, or 2 to decrypt a message:" << endl;
    getline(cin, option);
  }
  cout << endl;

// BEGIN ENCRYPTION
if (option == "1") {
  string message;
  string key;

  // PROMPT FOR MESSAGE TO ENCRYPT:
  cout << "Please input an alphabetical message without spaces to be encrypted:" << endl;
  getline(cin, message);

  // INPUT VALIDATION FOR MESSAGE:
  while (!all_of(message.begin(), message.end(), [](char character) {return isalpha(character);})) {
    cout << "Invalid message. Eneter an alphabetical message without spaces:" << endl;
    getline(cin, message);
  }
  cout << endl;

  // PROMPT FOR KEY:
  cout << "Please input an alphabetical key without spaces:" << endl;
  getline(cin, key);

  // INPUT VALIDATION FOR KEY:
  while (!all_of(key.begin(), key.end(), [](char character) {return isalpha(character);})) {
    cout << "Invalid key. Eneter an alphabetical key without spaces:" << endl;
    getline(cin, key);
  }
  cout << endl;

  // RESIZE KEY: TOO SHORT
  int i = 0;
  while (key.size() < message.size()) {
    key = key + key.at(i);
    i++;
  }

  // RESIZE KEY: TOO LONG
  while (key.size() > message.size()) {
    key.pop_back();
  }

  // FOR DEBUGGING ONLY: PRINT 'NEW' KEY
  // cout << "New Key: " << key << endl;

  // BEGINNING OF ENCRYPTION PROCESS
  string output = "";
  int xcoord;
  int ycoord;
  char keyVal;
  int j = 0;

  for (unsigned int i = 0; i < message.size(); i++) {

      // ENCRYPT UPPER CASE LETTERS
      if (isupper(message.at(i))) {
        xcoord = message.at(i) - 'A';
        keyVal = toupper(key.at(j));
        ycoord = keyVal - 'A';
        output += tableUpper[xcoord][ycoord];
      }

      // ENCRYPT LOWER CASE LETTERS
      else if (islower(message.at(i))) {
        xcoord = message.at(i) - 'a';
        keyVal = tolower(key.at(j));
        ycoord = keyVal - 'a';
        output += tableLower[xcoord][ycoord];
      }
    j++;
  }
  // OUTPUT ENCRYPTED MESSAGE:
  cout << "Encrypted message: " << output << endl;
}

// BEGIN DECRYPTION:
else if (option == "2") {
  string message;
  string key;

  // PROMPT FOR MESSAGE TO DECRYPT:
  cout << "Please input an alphabetical message without spaces to be decrypted:" << endl;
  getline(cin, message);
  
  // INPUT VALIDATION FOR MESSAGE:
  while (!all_of(message.begin(), message.end(), [](char character) {return isalpha(character);})) {
    cout << "Invalid message. Eneter an alphabetical message without spaces:" << endl;
    getline(cin, message);
  }
  cout << endl;

  // PROMPT FOR KEY:
  cout << "Please input an alphabetical key without spaces:" << endl;
  getline(cin, key);

  // INPUT VALIDATION FOR KEY:
  while (!all_of(key.begin(), key.end(), [](char character) {return isalpha(character);})) {
    cout << "Invalid key. Eneter an alphabetical key without spaces:" << endl;
    getline(cin, key);
  }
  cout << endl;

  // RESIZE KEY: TOO SHORT
  int i = 0;
  while (key.size() < message.size()) {
    key = key + key.at(i);
    i++;
  }

  // RESIZE KEY: TOO LONG
  while (key.size() > message.size()) {
    key.pop_back();
  }

  // FOR DEBUGGING ONLY: PRINT 'NEW' KEY
  // cout << "New Key: " << key << endl;

  // BEGIN DECRYPTION PROCESS:
  string output = "";
  int xcoord;
  int ycoord;
  char keyVal;
  int j = 0;

  for (unsigned int i = 0; i < message.size(); i++) {

      // DECRYPT UPPER CASE LETTERS
      if (isupper(message.at(i))) {
        keyVal = toupper(key.at(j));
        ycoord = keyVal - 'A';
        for (int h = 0; h < 26; h++) {
          if (tableUpper[h][ycoord] == message.at(i)) {
            xcoord = h;
            break;
          }
        }
        output += tableUpper[xcoord][0];
      }

      // DECRYPT LOWER CASE LETTERS
      else if (islower(message.at(i))) {
        keyVal = tolower(key.at(j));
        ycoord = keyVal - 'a';
        for (int h = 0; h < 26; h++) {
          if (tableLower[h][ycoord] == message.at(i)) {
            xcoord = h;
            break;
          }
        }
        output += tableLower[xcoord][0];
      }
    j++;
  }
  // OUTPUT DECRYPTED MESSAGE:
  cout << "Decrypted message: " << output << endl;
}
}