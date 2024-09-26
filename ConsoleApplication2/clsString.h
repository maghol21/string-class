#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class clsString
{

private:
    string _Value;
    int RandomNumber(int From, int To) {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    
public:

    enum enWhatToCount { Lower = 0, Upper = 1 };
    enum enTrimType { Left = 0, Right = 1, All = 2 };

    short length() {
		return this->Value.length();
    }

    clsString()
    {

        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;

    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };

    static void PrintFirstLetterOfWords(string str)
    {
        bool isFirst = true;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirst)
            {
                cout << str[i] << endl;
            }

            isFirst = str[i] == ' ';
        }
    }

    void PrintFirstLetterOfWords() {
        PrintFirstLetterOfWords(this->Value);
    }

    static string UpperEachFirstChar(string str)
    {
        bool isFirst = true;
        string newStr;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirst)
            {
                str[i] = toupper(str[i]);
            }

            isFirst = str[i] == ' ';
            newStr += str[i];
        }
        return newStr;
    }

    string UpperEachFirstChar()
    {
        return UpperEachFirstChar(this->Value);
    }

    static string LowerEachFirstChar(string str)
    {
        bool isFirst = true;
        string newStr;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirst)
            {
                str[i] = tolower(str[i]);
            }

            isFirst = str[i] == ' ';
            newStr += str[i];
        }
        return newStr;
    }

	string LowerEachFirstChar() {
		return LowerEachFirstChar(this->Value);
    }

    static string LowerString(string str)
    {
        for (auto& theChar : str)
        {
            theChar = tolower(theChar);
        }
        return str;
    }

	string LowerString() {
		return LowerString(this->Value);
	}


    static string UpperString(string str)
    {
        for (auto& theChar : str)
        {
            theChar = toupper(theChar);
        }
        return str;
    }

	string UpperString() {
		return UpperString(this->Value);
	}

    static char invertCharCase(char theChar)
    {
        return isupper(theChar) ? tolower(theChar) : toupper(theChar);
    }


    static string invertStringCase(string str)
    {
        for (auto& theChar : str)
        {
            theChar = invertCharCase(theChar);
        }
        return str;
    }

	string InvertStringCase() {
		return invertStringCase(this->Value);
	}

    static int LowerCount(string str)
    {
        int count = 0;
        for (auto& theChar : str) {
            if (islower(theChar))
            {
                count++;
            }
        }
        return count;
    }

	int LowerCount() {
		return LowerCount(this->Value);
	}

    static int UpperCount(string str)
    {
        int count = 0;
        for (auto& theChar : str) {
            if (isupper(theChar))
            {
                count++;
            }
        }
        return count;
    }


    int UpperCount() {
        return UpperCount(this->Value);
    }


    static int CountLetters(string str, enWhatToCount WhatToCount)
    {
        return WhatToCount == enWhatToCount::Upper ? UpperCount(str) : LowerCount(str);
    }


	int CountLetters(enWhatToCount WhatToCount) {
		return CountLetters(this->Value, WhatToCount);
	}

    static int CountLetter(string str, char letter, bool match = false)
    {
        int count = 0;
        if (match) {
            for (auto& theChar : str) {
                if (tolower(theChar) == tolower(letter)) count++;
            }
        }
        else {
            for (auto& theChar : str) {
                if (theChar == letter) count++;
            }
        }
        return count;
    }

	int CountLetter(char letter, bool match = false) {
		return CountLetter(this->Value, letter, match);
	}


    static bool isVowel(char letter)
    {
        return string("aeiou").find(tolower(letter)) != -1;
    }

    static int CountVowels(string str)
    {
        int count = 0;
        for (char& letter : str)
        {
            if (isVowel(letter)) count++;
        }
        return count;
    }

	int CountVowels() {
		return CountVowels(this->Value);
	}

    static void PrintEachWords(string str)
    {
        string delim = " ";
        short pos = 0;
        string sWord = "";

        while ((pos = str.find(delim)) != string::npos)
        {
            sWord = str.substr(0, pos);
            if (sWord != "")
            {
                cout << sWord << endl;
            }
            str.erase(0, pos + delim.length());
        }
        if (str != "")
        {
            cout << str << endl;
        }
    }

	void PrintEachWords() {
		PrintEachWords(this->Value);
	}

    static int CountEachWords(string str)
    {
        string delim = " ";
        short pos = 0;
        short count = 0;
        string sWord;
        while ((pos = str.find(delim)) != string::npos)
        {
            sWord = str.substr(0, pos);
            if (sWord != "") count++;
            str.erase(0, pos + delim.length());
        }
        if (str != "") count++;
        return count;
    }

	int CountEachWords() {
		return CountEachWords(this->Value);
	}

    static vector<string> split(string str, string delim)
    {
        short pos = 0;
        vector<string> vString;
        string sWord;
        while ((pos = str.find(delim)) != string::npos)
        {
            sWord = str.substr(0, pos);
            if (sWord != "") vString.push_back(sWord);
            str.erase(0, pos + delim.length());
        }
        if (str != "") vString.push_back(str);
        return vString;
    }

	vector<string> Split(string delim) {
		return split(this->Value, delim);
	}

    static string trimLeft(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                str.erase(0, i);
                return str;
            }
        }
        return "";

    }

	string TrimLeft() {
		return trimLeft(this->Value);
	}

    static string trimRight(string str)
    {
        for (int i = str.length() - 1; i > 0; i--)
        {
            if (str[i] != ' ')
            {
                str.erase(i + 1, str.length());
                return str;
            }
        }
        return "";
    }

    string TrimRight() {
        return trimRight(this->Value);
    }


    static string trim(string str, enTrimType TrimType = enTrimType::All)
    {
        switch (TrimType)
        {
        case Left:
            return trimLeft(str);
        case Right:
            return trimRight(str);
        case All:
        default:
            return trimLeft(trimRight(str));
        }
    }

	string Trim(enTrimType TrimType = enTrimType::All) {
		return trim(this->Value, TrimType);
	}

    static string join(vector<string> vString, string delim)
    {
        string str;
        for (string& item : vString)
        {
            str += item + delim;

        }
        return str.substr(0, str.length() - delim.length());
    }

    static string ReverseWords(string str)
    {
        vector<string> vString = split(str, " ");
        string tempStr;

        auto iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;
            tempStr += *iter + " ";

        }

        return tempStr.substr(0, tempStr.length() - 1);
    }

	string ReverseWords() {
		return ReverseWords(this->Value);
	}

    static string ReplaceWords(string str, string oldWord, string newWord, bool matchCase = false)
    {
        vector<string> vString = split(str, " ");
        string tempStr;

        if (matchCase)
        {
            for (string& Word : vString)
            {
                if (Word == oldWord)  Word = newWord;
            }
        }
        else {
            for (string& Word : vString)
            {
                if (LowerString(Word) == LowerString(oldWord)) Word = newWord;
            }
        }


        return join(vString, " ");
    }


    string ReplaceWords(string oldWord, string newWord, bool matchCase = false) {
		return ReplaceWords(this->Value, oldWord, newWord, matchCase);
    }

    static string RemovePunc(string str)
    {
        string newStr;
        for (char& letter : str)
        {
            if (!ispunct(letter))
            {
                newStr += letter;
            }
        }
        return newStr;

    }

	string RemovePunc() {
		return RemovePunc(this->Value);
	}

    static string readString(string msg)
    {
        string str;
        cout << msg;
        getline(cin, str);
        return str;
    }

	void read(string msg = "") {
		this->Value = readString(msg);
	}



};