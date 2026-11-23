/*
------------------------------------------------------------
Problem : Game Play Analysis IV (LeetCode 550)
Pattern : SQL / CTE / GROUP BY / MIN() / JOIN /
          Date Arithmetic / COUNT DISTINCT / Subquery /
          Type Casting / ROUND()

Time Complexity :
Conceptually O(N) for identifying each player's first login
and checking whether the player logged in again the next day,
assuming efficient join processing.

Space Complexity :
Depends on the database execution plan. The CTE, grouping,
and JOIN may require additional memory for intermediate
results.

Idea:
1. Create a Common Table Expression (CTE) named first_login
   to identify the first login date of every player.

       SELECT player_id, MIN(event_date)
       FROM Activity
       GROUP BY player_id

2. GROUP BY player_id ensures that each player appears once,
   while MIN(event_date) identifies their earliest login.

3. Join first_login with the original Activity table using:
   - Matching player_id.
   - event_date equal to first_date + 1.

   This checks whether a player logged in exactly one day
   after their first login.

4. Use COUNT(DISTINCT a.player_id) to count the number of
   players who logged in again on the following day.

   DISTINCT ensures that each qualifying player is counted
   only once, even if duplicate matching activity records
   exist.

5. Calculate the total number of players using:

       (SELECT COUNT(*) FROM first_login)

   Since first_login contains exactly one row per player,
   this gives the total number of distinct players.

6. Divide the number of qualifying players by the total
   number of players.

7. Cast the numerator to NUMERIC using ::numeric to ensure
   decimal division instead of integer division.

8. Use ROUND(..., 2) to round the final fraction to
   two decimal places.

Key Insight:
The problem asks for the fraction of players who logged in
again exactly one day after their first login.

The important distinction is that we must compare every
player's activity against their own first login date,
not against a common calendar date.

The CTE separates the problem into two logical steps:

    Step 1: Find each player's first login.
    Step 2: Check for activity on first_date + 1.

Important PostgreSQL Concepts:
- WITH (CTE) creates a temporary named result for the query.
- MIN(event_date) identifies the earliest login per player.
- Date arithmetic (first_date + 1) represents the next day.
- JOIN checks whether the next-day activity exists.
- COUNT(DISTINCT ...) counts qualifying players uniquely.
- COUNT(*) on first_login calculates the total player count.
- ::numeric prevents integer division.
- ROUND(..., 2) rounds the final fraction to two decimals.

Complexity Variables:
N = Total number of rows in the Activity table.
P = Number of distinct players.

Actual query performance depends on indexes, CTE
optimization, join strategy, database statistics, and
the execution plan.

------------------------------------------------------------
*/

WITH first_login AS (
    SELECT player_id, MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
)
SELECT ROUND(
    COUNT(DISTINCT a.player_id)::numeric
    / (SELECT COUNT(*) FROM first_login),
    2
) AS fraction
FROM first_login f
JOIN Activity a
    ON a.player_id = f.player_id
   AND a.event_date = f.first_date + 1;