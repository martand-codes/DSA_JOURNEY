/*
------------------------------------------------------------
Problem : Big Countries (LeetCode 595)
Pattern : SQL + Filtering + UNION

Time Complexity : O(N) for table scans, approximately
                  O(N log N) if UNION requires sorting
Space Complexity : O(N) for UNION deduplication

Idea:
- Retrieve the name, population, and area columns from
  the World table.
- Select countries with an area of at least 3,000,000.
- Select countries with a population of at least 25,000,000.
- Combine both result sets using UNION.
- UNION automatically removes duplicate rows.

Key Insight:
A country qualifies if it satisfies either condition:

    area >= 3000000
    OR
    population >= 25000000

UNION combines the results of two SELECT statements
and removes duplicate rows.

The original query using WHERE with OR expresses the
same logical condition more directly and is generally
simpler for this problem.

------------------------------------------------------------
*/

/*
SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;
*/

SELECT name, population, area 
FROM World 
WHERE area >= 3000000

UNION

SELECT name, population, area 
FROM World 
WHERE population >= 25000000;