#include<iostream>
#include<string>

using namespace std;



class Solution {
public:
    bool isPalindrome(int x) {
        // Jika x negatif, langsung return false (karena tidak mungkin palindrome)
        if (x < 0) return false;

        // Konversi integer ke string
        string s = to_string(x);

        // Cek apakah string tersebut palindrome
        int n = s.length();
        for (int i = 0; i < n/2 ; ++i) {
        if (s[i] != s[n-i-1]) {
            return false;  // Jika ada yang tidak sama, bukan palindrome
            }
        }
        
        return true;  // Jika semua elemen sesuai, maka palindrome
    }
};
