namespace 알고리즘테스트
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            int N;
            long B;

            string[] input = Console.ReadLine().Split();
            N = int.Parse(input[0]);
            B = long.Parse(input[1]);

            MatrixTest matrix = new MatrixTest(N, N);
            MatrixTest result = new MatrixTest(N, N);

            for (int i = 0; i < N; i++)
            {
                input = Console.ReadLine().Split();
                for (int j = 0; j < N; j++)
                {
                    matrix[i, j] = int.Parse(input[j]);
                }
            }

            result = matrix ^ B;
            result.PrintMatrix();
        }
    }
    internal class MatrixTest
    {
        int col;
        int row;

        int[,] matrix;
        public MatrixTest(int col, int row)
        {
            this.col = col;
            this.row = row;

            matrix = new int[col, row];
        }

        public MatrixTest(MatrixTest a)
        {
            col = a.col;
            row = a.row;

            matrix = new int[col, row];
            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    matrix[i, j] = a[i, j];
                }
            }
        }
        public int this[int col, int row]
        {
            get => matrix[col, row];
            set => matrix[col, row] = value;
        }
        //matrix 곱셈
        public static MatrixTest operator *(MatrixTest a, MatrixTest b)
        {
            if (a.row != b.col)
                throw new InvalidOperationException("Matrices cannot be multiplied: Number of columns in A must equal number of rows in B.");

            MatrixTest result = new MatrixTest(a.col, b.row);

            for (int i = 0; i < a.col; i++)
            {
                for (int j = 0; j < b.row; j++)
                {
                    for (int k = 0; k < a.row; k++)
                    {
                        result[i, j] += a[i, k] * b[k, j];
                    }
                }
            }

            return result % 1000;
        }
        public static MatrixTest operator ^(MatrixTest a, long b)
        {
            if (a.col != a.row)
                throw new InvalidOperationException("Matrix must be square matrix.");

            if (b < 1)
                throw new InvalidOperationException("Exp must be larger than zero");


            MatrixTest result = new MatrixTest(a.col, a.row);

            for (int i = 0; i < a.col; i++)
            {
                for (int j = 0; j < a.row; j++)
                {
                    result[i, j] = (i == j) ? 1 : 0;
                }
            }

            MatrixTest temp = new MatrixTest(a);
            for (; b > 0; b >>= 1)
            {
                if ((b & 1) == 1)
                {
                    result *= temp;
                }
                temp *= temp;
            }
            return result;
        }
        public static MatrixTest operator %(MatrixTest a, int module)
        {
            for (int i = 0; i < a.col; i++)
            {
                for (int j = 0; j < a.row; j++)
                {
                    a[i, j] %= module;
                }
            }
            return a;
        }

        public void PrintMatrix()
        {
            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}

