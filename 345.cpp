class Solution {
private:
bool isVow (char c)
{
    if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
    else return false;
}
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j)
        {
            if (isVow(s[i]) && isVow(s[j]))
            {
                swap(s[i] , s[j]) ;
                i++;
                j--;
            }
            else if ( isVow(s[i]) && !isVow(s[j]) )j--;
            else i++;
        }
        return s;
    }
};
