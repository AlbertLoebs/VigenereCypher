// this program encodes and decodes text using a vigenere cypher
// uses terminal user input

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

class vigenere{

	public:
		vigenere(string key);
		string encrypt(string);
 	 	string decrypt(string);
  		string simplify(string);
  		int keyshift();
  		
	private:
		char shift(char, int);
  		int shamt;
  		int key_index;
  		string keyword;
};

vigenere::vigenere(string key){
		
	keyword = simplify(key);
	key_index = -1;
}

string vigenere::encrypt(string plaintext){
	
int size = plaintext.size();
string vigeneretext = "";
		
		for(int i = 0; i < size; i++){
			vigeneretext += shift(plaintext[i], keyshift());
		}
	return vigeneretext;
}

int vigenere::keyshift(){

	key_index++;

	if(key_index >= keyword.size()){
		key_index = 0;
	}
	
		return keyword.at(key_index) - 'A';
}

string vigenere:: decrypt(string ciphertext){
	
string plaintext = "";	
int size = ciphertext.size();
	
	for(int i = 0; i < size; i++){
		plaintext += shift(ciphertext[i], - keyshift());
	}
	return plaintext;
}

string vigenere::simplify(string text){
	
string simplify = "";
int size = text.size();
	
	for(int i = 0; i < size; i++){
	if(isalnum(text[i])){
			simplify = simplify + (char) toupper(text[i]);
		}
	}
		return simplify;
}

char vigenere::shift(char c, int shamt){
	
int result = (c-'A'+shamt);

	if (result >= 26) result = result - 26;
	if (result < 0) result = result + 26;
	
	return result+'A';
}


int main(int argc, char *argv[]){
 
 if (argc != 3){
    cerr << "USAGE: " << argv[0] << " -d|e shiftAmount" << endl;
    exit(1);
  }
 
  string shamt = (argv[2]);
  
  bool encrypt;
  string option( argv[1]);
  string line;
  string encodedLine;	
  
  if (option == "-e"){
    encrypt = true;
  }	else {
    encrypt = false;
  }
  
  vigenere cipher(shamt);
  
  while( getline(cin, line) ){
    if (encrypt){
      encodedLine = cipher.encrypt(cipher.simplify(line));
    } else {
      encodedLine = cipher.decrypt(line);
    }	
    cout << encodedLine << endl;
  }
  
  return 0;
}
