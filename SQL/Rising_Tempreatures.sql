/*
------------------------------------------------------------
Problem : Rising Temperature (LeetCode 197)
Pattern : SQL + SELF JOIN + Date Comparison

Time Complexity : O(N log N) with indexed date lookups
Space Complexity : O(N) for the join operation
                    (execution-plan dependent)

Idea:
- Use the Weather table twice with different aliases:
    today     → Represents the current day's weather.
    yesterday → Represents the previous day's weather.
- Perform a SELF JOIN to match consecutive dates.
- Match records where the date difference is exactly one day.
- Filter records where today's temperature is greater
  than yesterday's temperature.
- Return the IDs of the qualifying records.

Key Insight:
A SELF JOIN allows us to compare rows within the same table.

    today.recordDate - yesterday.recordDate = 1

ensures that the two records belong to consecutive days.

    today.temperature > yesterday.temperature

ensures that the temperature increased compared to
the previous day.

Only the current day's ID is returned.

------------------------------------------------------------
*/

SELECT today.id
FROM Weather today
JOIN Weather yesterday 
    ON today.recordDate - yesterday.recordDate = 1
WHERE today.temperature > yesterday.temperature;