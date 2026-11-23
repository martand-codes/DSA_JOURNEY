/*
------------------------------------------------------------
Problem : Monthly Transactions I (LeetCode 1193)
Pattern : SQL / Date Formatting / Aggregate Functions /
          Conditional Aggregation / CASE WHEN / GROUP BY

Time Complexity :
O(N) — Conceptual estimate for scanning all rows in the
Transactions table and calculating the aggregate values.

Space Complexity :
Depends on the database execution plan. GROUP BY may require
additional memory for storing intermediate groups and
aggregate results.

Idea:
1. Convert each transaction date into a year-month format
   using TO_CHAR():

       TO_CHAR(trans_date, 'yyyy-mm')

   This extracts the transaction month in the required
   format, such as '2018-12'.

2. Group the transactions by month and country so that
   each month-country combination produces one result row.

3. Calculate the total number of transactions using:

       COUNT(amount)

   This counts non-NULL amount values.

4. Calculate the number of approved transactions using:

       COUNT(CASE WHEN state = 'approved' THEN id
                  ELSE NULL END)

   - If the transaction is approved, return its id.
   - Otherwise, return NULL.
   - COUNT() ignores NULL values, effectively counting
     only approved transactions.

5. Calculate the total transaction amount using:

       SUM(amount)

   This adds the amounts of all transactions in the group.

6. Calculate the total approved transaction amount using:

       SUM(CASE WHEN state = 'approved' THEN amount
                ELSE 0 END)

   - Include the amount when the transaction is approved.
   - Otherwise, contribute zero to the sum.

7. Return the aggregated results for every month-country
   combination.

Key Insight:
The main concept is conditional aggregation: multiple
statistics can be calculated from the same group of rows
using aggregate functions combined with CASE WHEN.

Important SQL Concepts:
- TO_CHAR() formats dates into the required year-month string.
- COUNT(CASE WHEN ...) performs conditional counting because
  COUNT() ignores NULL values.
- SUM(CASE WHEN ...) performs conditional summation.
- GROUP BY month, country creates a separate group for
  every month-country combination.

Why use CASE WHEN?
It allows us to apply a condition inside an aggregate
function without filtering out the remaining transactions.

For example, using WHERE state = 'approved' would remove
unapproved transactions and make it impossible to calculate
the overall transaction count and total amount in the same
group.

Complexity Variables:
N = Total number of rows in the Transactions table.

Actual query performance depends on the execution plan,
date formatting, grouping strategy, and available indexes.

------------------------------------------------------------
*/

SELECT to_char(trans_date,'yyyy-mm') as month, country, 
COUNT(amount) as trans_count, 
COUNT(CASE WHEN state = 'approved' then id else null end) as approved_count,
SUM(amount) as trans_total_amount,
SUM(CASE WHEN state = 'approved' then amount else 0 end) as approved_total_amount 
FROM Transactions 
GROUP BY month,country