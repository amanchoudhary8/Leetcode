# Write your MySQL query statement below
select distinct p.email as Email
from Person p inner join Person q
on p.id<>q.id and p.email=q.email;
