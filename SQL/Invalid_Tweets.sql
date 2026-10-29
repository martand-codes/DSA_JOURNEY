/*
------------------------------------------------------------
Problem : Invalid Tweets (LeetCode 1683)
Pattern : SQL + Filtering + String Functions

Time Complexity : O(N) for scanning all tweets
Space Complexity : O(1) auxiliary space

Idea:
- Retrieve tweet_id from the Tweets table.
- Use the LENGTH() function to calculate the number
  of characters in each tweet's content.
- Filter tweets whose content length exceeds 15 characters.

Key Insight:
A tweet is considered invalid if its content contains
more than 15 characters.

    LENGTH(content) > 15

The WHERE clause ensures that only invalid tweets
are included in the result.

------------------------------------------------------------
*/

SELECT tweet_id 
FROM Tweets
WHERE LENGTH(content) > 15;