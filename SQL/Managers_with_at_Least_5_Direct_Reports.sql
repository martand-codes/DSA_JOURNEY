/*
------------------------------------------------------------
Problem : Managers with at Least 5 Direct Reports (LeetCode #570)
Pattern : SQL + SELF JOIN + GROUP BY + HAVING + COUNT

Time Complexity : Execution-plan dependent; typically O(N)
Space Complexity : Execution-plan dependent; grouping may require O(N)

Idea:
- Perform a SELF JOIN on the Employee table.
- Match each manager's id (A.id) with their employees' managerId (B.managerId).
- Group records by manager id and name.
- Count the number of direct reports using COUNT(B.id).
- Use HAVING to retain only managers with at least 5 direct reports.
- Return the qualifying managers' names.

Key Insight:
- SELF JOIN allows us to establish the manager-employee relationship
  within the same table.
- GROUP BY creates one group per manager.
- HAVING filters groups after aggregation, unlike WHERE,
  which filters individual rows before grouping.
- COUNT(B.id) counts the manager's matching direct reports.

------------------------------------------------------------
*/

SELECT A.name
FROM Employee A
INNER JOIN Employee B
ON A.id = B.managerId
GROUP BY 
    A.id,
    A.name
HAVING COUNT(B.id) >= 5;