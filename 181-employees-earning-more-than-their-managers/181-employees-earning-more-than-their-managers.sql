# Write your MySQL query statement below

SELECT e1.name as Employee
FROM EMPLOYEE e1
INNER JOIN EMPLOYEE e2
ON e1.managerId = e2.id
where e1.salary>e2.salary;


