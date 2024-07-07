def solve(n1,n2,k1,k2):    
    MOD = 10**8
    dp = [[[[0]*(k2+1) for _ in range(k1+1)] for _ in range(n2+1) ] for _ in range(n1+1)]
    
    dp[0][0][0][0] = 1
    
    for i in range(n1+1):
        for j in range(n2+1):
            for f in range(k1+1):
                for h in range(k2+1):
                    if f<k1 and i<n1:
                        dp[i+1][j][f+1][0] += dp[i][j][f][h]
                        dp[i+1][j][f+1][0] %= MOD
                    if h<k2 and j<n2:
                        dp[i][j+1][0][h+1] += dp[i][j][f][h]
                        dp[i][j+1][0][h+1] %= MOD
                        
    result = 0
    for i in range(k1+1):
        for j in range(k2+1):
            result+=dp[n1][n2][i][j]
            result%=MOD
    
    return result

n1,n2,k1,k2 = map(int,input().split())
print(solve(n1,n2,k1,k2))
                
                        
