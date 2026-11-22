/*
------------------------------------------------------------
Problem : Queries Quality and Percentage (LeetCode 1211)
Pattern : SQL / Aggregate Functions / AVG / SUM / Conditional
          Aggregation / Type Casting / GROUP BY / NULL Filtering

Time Complexity :
O(N) — Conceptual estimate for scanning all rows in the
Queries table and calculating the aggregate values.

Space Complexity :
Depends on the database execution plan. GROUP BY may require
additional memory for grouping and aggregation.

Idea:
1. Filter out rows where query_name IS NULL using the WHERE
   clause because only valid query names should appear in
   the result.
2. Group the remaining records by query_name so that each
   query name gets its own aggregate statistics.
3. Calculate the quality of each query using:

       Quality = AVG(rating / position)

   - Divide each rating by its corresponding position.
   - Cast position to DECIMAL using ::decimal to ensure
     floating-point division instead of integer division.
   - AVG() calculates the average of these individual ratios.
4. Round the quality value to 2 decimal places using ROUND().
5. Calculate the poor query percentage using:

       Poor Query Percentage =
       (Number of queries with rating < 3 / Total queries) * 100

   - (rating < 3) evaluates to TRUE or FALSE.
   - ::int converts TRUE to 1 and FALSE to 0.
   - SUM() counts the number of poor queries.
   - COUNT(*) counts all rows in the current query_name group.
6. Multiply by 100.0 to ensure decimal arithmetic while
   calculating the percentage.
7. Round the resulting percentage to 2 decimal places.

Key Insight:
The quality and poor query percentage are two different
aggregations performed over the same group of records.

- AVG(rating / position) calculates the average quality
  score, not AVG(rating) / AVG(position).
- SUM((rating < 3)::int) acts as conditional counting.
- COUNT(*) provides the total number of queries in each group.
- GROUP BY query_name ensures both metrics are calculated
  independently for every query name.

Important PostgreSQL Concepts:
- ::decimal converts a value to a decimal-compatible type.
- Boolean-to-integer casting allows conditions to be
  aggregated using SUM().
- WHERE filters rows before grouping and aggregation.
- ROUND(..., 2) rounds numeric results to two decimal places.

Complexity Variables:
N = Total number of rows in the Queries table.

Actual query performance depends on the database execution
plan and the cost of grouping and aggregation.

------------------------------------------------------------
*/

SELECT query_name,
    ROUND(AVG(rating / position::decimal), 2) AS quality,
    ROUND(SUM((rating < 3)::int) * 100. / COUNT(*), 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name;