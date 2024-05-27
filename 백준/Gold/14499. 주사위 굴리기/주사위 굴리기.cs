namespace 알고리즘테스트
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            int N, M, x, y, K;
            string[] str = Console.ReadLine().Split(" ");
            N = int.Parse(str[0]);
            M = int.Parse(str[1]);
            x = int.Parse(str[2]);
            y = int.Parse(str[3]);
            K = int.Parse(str[4]);

            int[,] map = new int[N, M];
            for (int i = 0; i < N; i++)
            {
                str = Console.ReadLine().Split(" ");
                for (int j = 0; j < M; j++)
                {
                    map[i, j] = int.Parse(str[j]);
                }
            }

            str = Console.ReadLine().Split(" ");
            int[] command = new int[K];
            for (int i = 0; i < K; i++)
            {
                command[i] = int.Parse(str[i]);
            }

            //동쪽, 서쪽, 북쪽, 남쪽 1, 2, 3, 4


            int[,] commandMove = new int[4, 2]
            {
                {0, 1},
                {0, -1},
                {-1, 0},
                {1, 0},
            };

            //top, front, right, left, back, bottom
            int[,] commandDiceMove = new int[4, 6]
            {
               {3, 1, 0, 5, 4, 2},
               {2, 1, 5, 0, 4, 3},
               {4, 0, 2, 3, 5, 1},
               {1, 5, 2, 3, 0, 4}
            };

            int[] dice = new int[6];
            int[] tempDice = new int[6];

            int currentTop = 0;
            int currentButtom = 5;

            for (int i = 0; i < K; i++)
            {
                int commandKey = command[i] - 1;

                int nextX = x + commandMove[commandKey, 0];
                int nextY = y + commandMove[commandKey, 1];

                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                {
                    continue;
                }

                x = nextX;
                y = nextY;

                for (int j = 0; j < dice.Length; j++)
                {
                    tempDice[j] = dice[j];
                }

                for (int j = 0; j < dice.Length; j++)
                {
                    dice[j] = tempDice[commandDiceMove[commandKey, j]];
                }

                if (map[x, y] == 0)
                {
                    map[x, y] = dice[currentButtom];
                }
                else
                {
                    dice[currentButtom] = map[x, y];
                    map[x, y] = 0;
                }


                //Console.WriteLine("x : " + x + " y : " + y + "currentTop : " + currentTop);
                Console.WriteLine(dice[currentTop]);
            }
        }
    }
}

