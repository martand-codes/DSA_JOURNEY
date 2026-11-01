/*
------------------------------------------------------------
Problem : Employee Bonus (LeetCode #577)
Pattern : SQL + LEFT JOIN + NULL Handling + Filtering

Time Complexity : Execution-plan dependent; typically O(N + M)
Space Complexity : Execution-plan dependent; may require O(N + M)
                  for hash join operations.

Idea:
- Perform a LEFT JOIN between Employee and Bonus using empId.
- Preserve all employees, including those without bonus records.
- Filter employees whose bonus is less than 1000.
- Include employees whose bonus is NULL (no matching bonus record).
- Return the employee name and bonus amount.

Key Insight:
- LEFT JOIN retains every row from the left table.
- When no matching bonus record exists, B.bonus becomes NULL.
- NULL cannot be checked using = or !=.
- Use IS NULL to identify missing bonus values.

------------------------------------------------------------
*/

SELECT A.name, B.bonus
FROM Employee A
LEFT JOIN Bonus B
ON A.empId = B.empId
WHERE bonus < 1000 OR bonus IS null;