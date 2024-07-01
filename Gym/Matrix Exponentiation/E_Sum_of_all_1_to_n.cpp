graph multiply(graph &a, graph &b)
{
    int n = a.size();
    graph c(n, vi(n, 0));
    fr(i, n)
    {
        fr(j, n)
        {
            fr(k, n)
            {
                c[i][j] = (c[i][j] + (a[i][k] * 1LL * b[k][j]) % N) % N;
            }
        }
    }
    return c;
}

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void solve()
{
    int k;
    cin >> k;
    k++;
    graph board(65, vi(65, 0));
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            for (int d = 0; d < 8; d++)
            {
                int xx = dx[d] + row;
                int yy = dy[d] + col;
                if (valid(xx, yy))
                {
                    board[xx * 8 + yy][row * 8 + col] = 1;
                }
            }
        }
    }

    graph res(65, vi(65, 0));

    fr(i, 65)
    {
        fr(j, 65)
        {
            res[i][j] = (i == j);
        }
    }

    for (int i = 0; i < 65; i++)
    {
        board[i][64] = 1;
    }

    while (k > 0)
    {
        if (k & 1)
        {
            res = multiply(board, res);
        }
        board = multiply(board, board);
        k >>= 1;
    }

    cout << res[0][64];
}
