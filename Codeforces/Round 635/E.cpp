Assume we have n positions number from 0 to n−1.We delete the letters in S

and put them in these positions.

We can simply see that the operations described in the statement can be changed to these:

    Put the first letter arbitrarily in the positions.

    Put other letters either at the front or at the back of the sequence of letters we put in the positions.

And the dp is quite obvious now:

Let dp[i][j]
be the answer when we delete the first i letters in S and the start of the sequence in the positions is j.We can choose to put the i+1 letter either at the front or at the back of the sequence.If the position we put this letter in is between 0 and m−1,we need to make sure this letter equals to the corresponding letter in T

.

That means:(if the dp is valid)

dp[i+1][j−1]+=dp[i][j]

dp[i+1][j]+=dp[i][j]

Of course,dp[1][j]=2
if j>=m or S[j]==T[j].The final answer is ∑ni=mdp[i][0].

https://codeforces.com/submissions/sjc061031