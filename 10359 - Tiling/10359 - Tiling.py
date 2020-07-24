def main():
    dp = [0] * 252
    dp[0] = 1
    dp[1] = 1

    for i in range( 2, 251 ):
        dp[i] += dp[i-1]
        dp[i] += dp[i-2]
        dp[i] += dp[i-2]
        
    while True:
        try:
            n = int( input() )
            print ( dp[n] )
        except EOFError:
            break
        
if __name__ == '__main__':
    main()
    