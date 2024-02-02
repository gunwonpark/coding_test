using System.Linq;

public class Solution {
    public string solution(string s) {    
        return new string(s.OrderBy(x => -x).ToArray());
    }
}