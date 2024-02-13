public class Solution {
    public bool solution(string s) {
        int temp;
        if(s.Length < 4 || s.Length > 6 || s.Length == 5) return false;
        if(s.Contains('e')) return false;
        return int.TryParse(s, out temp);
    }
}