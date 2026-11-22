/*
------------------------------------------------------------
Problem : Project Employees I (LeetCode 1075)
Pattern : SQL / LEFT JOIN / Aggregate Functions / GROUP BY / AVG / Type Casting

Time Complexity :
O(P + E) — Conceptual estimate for processing the Project and
Employee tables, assuming efficient join processing.

Space Complexity :
Depends on the database execution plan. The JOIN and GROUP BY
operations may require additional memory for intermediate
results and aggregation.

Idea:
1. Start with the Project table (A) as the driving table.
2. Perform a LEFT JOIN with the Employee table (B) using
   employee_id as the matching column.
3. A LEFT JOIN ensures that project records are preserved
   even when a matching employee record is unavailable.
4. Group the joined records by project_id so that each
   project gets its own aggregate result.
5. Use AVG(B.experience_years) to calculate the average
   experience of employees assigned to each project.
6. Cast the AVG result to NUMERIC using ::numeric so that
   ROUND() can round the result to exactly 2 decimal places.
7. Return project_id and the calculated average_years.

Key Insight:
The main idea is to calculate the average experience
separately for every project.

- LEFT JOIN connects projects with their assigned employees.
- GROUP BY project_id creates one group per project.
- AVG() automatically ignores NULL values.
- ROUND(..., 2) formats the average to 2 decimal places.

Why LEFT JOIN?
Using LEFT JOIN preserves all projects from the Project
table, including projects without matching employee records.

Why ::numeric?
PostgreSQL's ROUND() function supports the two-argument
form for NUMERIC values. Casting the AVG result ensures
that ROUND(..., 2) works correctly.

Complexity Variables:
P = Number of rows in the Project table.
E = Number of rows in the Employee table.

Actual query performance depends on indexes, join strategy,
database statistics, and the execution plan.

------------------------------------------------------------
*/

SELECT A.project_id,
ROUND(AVG(B.experience_years):: numeric, 2) AS average_years
FROM Project A
LEFT JOIN Employee B
ON  A.employee_id = B.employee_id
GROUP BY A.project_id;
