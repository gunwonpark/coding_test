using System;
using System.Linq;
using System.Collections.Generic;

public class Solution
{
    List<List<bool>> visited = new List<List<bool>>();
    int[,] direction = new int[,] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    List<int> answer = new List<int>();
    public int[] solution(string[] maps)
    {
        for (int i = 0; i < maps.Length; i++)
        {
            visited.Add(new List<bool>());
            for (int j = 0; j < maps[0].Length; j++)
            {
                visited[i].Add(false);
            }
        }
        // stack으로 상하좌우 방문
        // visit으로 방문한 곳 표현
        for (int i = 0; i < maps.Length; i++)
        {
            for (int j = 0; j < maps[0].Length; j++)
            {
                if (maps[i][j] != 'X' && !visited[i][j])
                {
                    visited[i][j] = true;
                    Bfs(i,j,maps);
                }
            }
        }
        if(answer.Count == 0) answer.Add(-1);
        answer.Sort();
        return answer.ToArray();
    }

    private void Bfs(int y, int x, string[] maps)
    {
        Stack<Pos> stack = new Stack<Pos>();
        stack.Push(new Pos(y, x));
        answer.Add((int.Parse(maps[y][x].ToString())));

        while(stack.Count > 0)
        {
            Pos curPosition = stack.Pop();

            for (int i = 0; i < direction.GetLength(0); i++)
                    {
                        Pos nextPosition = curPosition + new Pos(direction[i,0], direction[i,1]);
                        int newX = nextPosition.x;
                        int newY = nextPosition.y;
                        if (newX < 0 || newX >= maps[0].Length || newY < 0 || newY >= maps.Length)
                        {
                            continue;
                        }
                        if (maps[newY][newX] != 'X' && !visited[newY][newX])
                        {
                            stack.Push(nextPosition);
                            visited[newY][newX] = true;
                            answer[answer.Count - 1] += int.Parse(maps[newY][newX].ToString());
                        }
                    }
                }
            }
        }
        public struct Pos
        {
            public int x, y;
            public Pos(int _y, int _x)
            {
                x = _x;
                y = _y;
            }
            public static Pos operator +(Pos a, Pos b)
            {
                return new Pos(a.y + b.y, a.x + b.x);
            }
        }