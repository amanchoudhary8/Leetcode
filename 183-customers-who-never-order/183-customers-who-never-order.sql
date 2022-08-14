# Write your MySQL query statement below
Select name as Customers
From Customers 
where not exists (select * from Orders where Orders.CustomerId=Customers.id limit 1);
