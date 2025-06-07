class Solution {
public:
    bool isPalin(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool check(const string& a, const string& b) {
        int i = 0, j = a.length() - 1;
        while (i < j && a[i] == b[j]) {
            i++;
            j--;
        }
        return isPalin(a, i, j) || isPalin(b, i, j);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a); 
    }
};
