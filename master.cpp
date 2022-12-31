#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>


using namespace std;

string reversed(string& s) {
    string out = "";
    for (int i = s.length(); i >= 0; i--)
        out += s[i];
    return out;
}

char toLowChar(const char c) {
    int n = int(c);
    if (n >= int('A') && n <= int('Z'))
        n += 32;
    char out = char(n);
    return out;
}

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i';
}

string lower(const string& s) {
    string out = "";
    for (int i = 0; i < s.length(); i++) {
        out += toLowChar(s[i]);
    }
    return out;
}

bool metOneTime(char c, string& word) {
    // Функция возвращает true если символ встертился 0 или 1 раз иначе false
    int n = 0;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == c)
            n += 1;
    }
    if (n <= 1)
        return true;
    return false;
}

// Класс для адреса
class Address {
private:
    string street;  // Название улицы
    int house;      // Номер дома
    int flat;       // Номер кватиры
public:
    // Дефолтный конструктор
    Address() {
        this->street = "None";
        this->house = 0;
        this->flat = 0;
    }
    // Конструктор с параметрами
    Address(string street, int house, int flat) {
        this->street = street;
        this->house = house;
        this->flat = flat;
    }
    // Уставновка значений через стандартный ввод, с сообщениями, которые выводятся перед вводом
    void setThroughInput(string mess1 = "", string mess2 = "", string mess3 = "") {
        cout << mess1;
        cin >> this->street;
        cout << mess2;
        cin >> this->house;
        cout << mess3;
        cin >> this->flat;
    }

    // Сеттеры
    // Для улицы
    void setStreet(string street) {
        this->street = street;
    }
    // Для номера дома
    void setHouse(int house) {
        this->house = house;
    }
    // Для квартиры
    void setFlat(int flat) {
        this->flat = flat;
    }

};

// Kata 1
//Stop gninnipS My sdroW!
vector<string> split(const string& inpWord) {
    string word = "";
    int index = 0;
    vector<string> out;
    for (int i = 0; i < inpWord.length(); i++) {
        if (inpWord[i] != ' ') {
            word += string(1, inpWord[i]);;
        }
        else {
            out.push_back(word);
            word = "";
        }
    }
    out.push_back(word);
    return out;
}

string spinWords(string& str)
{
    vector<string> words = split(str);
    string out = "";
    for (auto i = words.begin(); i != words.end(); ++i) {
        if (i->length() >= 5) {
            string rev = reversed(*i);
            out += rev;
        }
        else
            out += *i;
        out += " ";
    }

    
    return out;
}

vector<int> hms(float t) {
    int h, m, sec;
    h = (int)t;
    m = (int)t * 60;
    m %= 60;
    sec = (int)t * 60 * 60;
    sec %= 60;
    vector<int> out = {h, m, sec};
    return out;
}
/*
// Kata 2
// Tortoise racing
int* race(int v2, int v1, int g) {
    float t = (float)g / (v1 - v2);
    int* out = new int[3]{ -1, -1, -1 };
    if (t < 0)
        return out;
    else {
        vector<int> time = hms(t);
        out[0] = time[0];
        out[1] = time[1];
        out[2] = time[2];
    }
    return out;
}*/

// Kata 3
// Pyramid Array
vector<vector<int>> pyramid(int n) {
    vector<vector<int>> out;
    int size = 1;
    for (int i = 0; i < n; i++) {
        out.push_back(vector<int>{});
        for (int j = 0; j < size; j++)
            out[i].push_back(1);
        size++;
    }
    return out;
}

// Kata 4
// Multiples of 3 or 5
int sollution(int n) {
    int out = 0;
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            out += i;
    }
    return out;
}

// Kata 5
// Even or Odd
string even_or_odd(int number)
{
    return number % 2 == 0 ? "Even" : "Odd";
}

// Kata 6
// Find the odd int
int findOdd(vector<int>& nums) {
    map<int, int> nums_map;

    for (int i = 0; i < nums.size(); i++) {
        if (nums_map.find(nums[i]) != nums_map.end())
            nums_map[nums[i]] += 1;
        else
            nums_map[nums[i]] = 1;
    }
    for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter)
        if (iter->second % 2 == 1)
            return iter->first;

}

// Kata 7
// Sum of Digits / Digital Root
int digital_root(int n) {
    int sum = 0;
    while (n > 9) {
        sum += n % 10;
        n /= 10;
    }
    sum += n;
    if(sum > 9)
        return digital_root(sum);
    else
        return sum;
}

// Kata 8
// Duplicate Encoder
// Used lower func -> toLowChar
// Used metOneTime
string duplicate_encoder(string& word) {
    word = lower(word);
    string out = "";
    for (int i = 0; i < word.size(); i++) {
        if (metOneTime(word[i], word))
            out += "(";
        else
            out += ")";
    }
    return out;
}

// Kata 9
// Take a ten minutes walk
bool isValidWalk(vector<char> walk) {
    int x = 0, y = 0;
    if (walk.size() != 10)
        return false;
    for (int i = 0; i < walk.size(); i++) {
        switch (walk[i]) {
            case 'w':
                x -= 1;
                break;
            case 'e':
                x += 1;
                break;
            case 'n':
                y += 1;
                break;
            case 's':
                y -= 1;
                break;
        }
    }
    if (x == 0 && y == 0)
        return true;
    return false;
}



std::string disemvowel(const std::string& str) {
    string lowerStr = lower(str);
    string out = "";
    for (int i = 0; i < lowerStr.length(); i++) {
        if (!isVowel(lowerStr[i]))
            out += str[i];
    }
    return out;
}

int main() {
    cout << disemvowel("Hello wolrd!");

}