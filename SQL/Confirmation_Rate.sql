/*
------------------------------------------------------------
Problem : Confirmation Rate (LeetCode #1934)
Pattern : SQL + LEFT JOIN + CASE WHEN + AVG + ROUND

Time Complexity : Execution-plan dependent; typically O(S + C)
Space Complexity : Execution-plan dependent; grouping/join may
                   require O(S + C) additional space.

Idea:
- Perform a LEFT JOIN between Signups and Confirmations
  using user_id.
- Use CASE WHEN to convert confirmed actions into 1.0
  and timeout actions into 0.0.
- Calculate AVG() to determine the confirmation rate.
- ROUND() the result to 2 decimal places.
- GROUP BY user_id to calculate the rate for each user.

Key Insight:
- The average of 1.0 and 0.0 represents:
  confirmed requests / total requests.
- LEFT JOIN ensures users without confirmation requests
  are still included.
- PostgreSQL AVG() ignores NULL values, but the LEFT JOIN
  produces a NULL action that CASE converts to 0.0.
  Therefore, users without requests correctly get 0.00.

------------------------------------------------------------
*/

SELECT 
    A.user_id, 
    ROUND(AVG(CASE WHEN B.action = 'confirmed' THEN 1.0 ELSE 0.0 END), 2) AS confirmation_rate
FROM Signups A
LEFT JOIN Confirmations B 
    ON A.user_id = B.user_id
GROUP BY A.user_id;