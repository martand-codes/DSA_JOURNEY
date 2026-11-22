/*
------------------------------------------------------------
Problem : Percentage of Users Attended a Contest (LeetCode 1633)
Pattern : SQL / JOIN / Aggregate Functions / COUNT DISTINCT /
          Scalar Subquery / GROUP BY / ORDER BY

Time Complexity :
Conceptually O(R + U) for processing the Register and Users
tables, assuming efficient join and aggregation operations.

Space Complexity :
Depends on the database execution plan. The JOIN, DISTINCT,
GROUP BY, and sorting operations may require additional
memory for intermediate results.

Idea:
1. Use Register (B) as the driving table because we need to
   calculate the percentage of users registered for each
   contest.
2. Perform a LEFT JOIN with Users (A) using user_id.
3. Group the resulting records by contest_id so that each
   contest gets its own aggregate result.
4. Use COUNT(DISTINCT A.user_id) to count the unique users
   registered for each contest.
5. Calculate the total number of users using a scalar
   subquery:
       (SELECT COUNT(*) FROM Users)
6. Divide the number of registered users by the total number
   of users and multiply by 100 to obtain the percentage.
7. Cast the numerator to NUMERIC using ::numeric to ensure
   decimal arithmetic instead of integer division.
8. Use ROUND(..., 2) to round the percentage to two decimal
   places.
9. Sort the results by:
   - percentage in descending order.
   - contest_id in ascending order when percentages tie.

Key Insight:
The percentage is calculated independently for every contest:

    Percentage = (Unique Registered Users / Total Users) * 100

Important SQL Concepts:
- COUNT(DISTINCT user_id) prevents duplicate registrations
  from being counted more than once.
- The scalar subquery calculates the total user count once
  logically for the denominator.
- GROUP BY contest_id produces one result per contest.
- ::numeric ensures decimal division and avoids integer
  truncation.
- ORDER BY percentage DESC, contest_id ASC implements the
  required sorting priority.

Complexity Variables:
R = Number of rows in the Register table.
U = Number of rows in the Users table.

Actual query performance depends on indexes, database
statistics, join strategy, aggregation, sorting, and the
execution plan.

------------------------------------------------------------
*/

SELECT B.contest_id,
ROUND(COUNT(DISTINCT A.user_id)::numeric * 100 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register B
LEFT JOIN Users A
ON A.user_id = B.user_id
GROUP BY B.contest_id
ORDER BY percentage DESC, B.contest_id ASC;