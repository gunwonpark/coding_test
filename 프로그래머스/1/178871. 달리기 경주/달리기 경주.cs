using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string[] solution(string[] players, string[] callings) {
        Dictionary<string, int> dic = new Dictionary<string, int>();
            for (int i = 0; i < players.Length; i++)
            {
                dic.Add(players[i], i);
            }
            foreach (var str in callings)
            {
                dic[str]--;
                dic[players[dic[str]]]++;
                Array.Reverse(players, dic[str], 2);
            }

            return players;
    }
}