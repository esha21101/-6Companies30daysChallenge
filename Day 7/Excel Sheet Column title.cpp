class Solution {
public:
    string convertToTitle(int col) {
       if (col == 0) return "";
        col--; 
        char ch = 'A' + col % 26;
        return convertToTitle(col / 26) + ch; 
    }
};