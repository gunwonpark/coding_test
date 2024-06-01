namespace 알고리즘테스트
{

    internal class Program
    {
        private static void Main(string[] args)
        {
            int N, M, K;
            string[] input = Console.ReadLine().Split(" ");

            N = int.Parse(input[0]);
            M = int.Parse(input[1]);

            int[,] A = new int[N, M];

            for (int i = 0; i < N; i++)
            {
                input = Console.ReadLine().Split(" ");
                for (int j = 0; j < M; j++)
                {
                    A[i, j] = int.Parse(input[j]);
                }
            }

            input = Console.ReadLine().Split(" ");

            M = int.Parse(input[0]);
            K = int.Parse(input[1]);

            int[,] B = new int[M, K];

            for (int i = 0; i < M; i++)
            {
                input = Console.ReadLine().Split(" ");
                for (int j = 0; j < K; j++)
                {
                    B[i, j] = int.Parse(input[j]);
                }
            }

            printMatrix(MatrixMultifly(A, B));

        }
        public static int[,] MatrixMultifly(int[,] A, int[,] B)
        {
            if (A.GetLength(1) != B.GetLength(0))
            {
                throw new InvalidOperationException("A's row ans B's column should be same");
            }

            int[,] result = new int[A.GetLength(0), B.GetLength(1)];

            for (int i = 0; i < A.GetLength(0); i++)
            {
                for (int j = 0; j < B.GetLength(1); j++)
                {
                    for (int k = 0; k < A.GetLength(1); k++)
                    {
                        result[i, j] += A[i, k] * B[k, j];
                    }
                }
            }

            return result;
        }

        public static void printMatrix(int[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}

