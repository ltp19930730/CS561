drop view if exists a1;
create view a1 as
select cust, prod as PRODUCT, max(quant) as NY_max 
from sales 
where state='NY' and year > 2000 
group by cust, prod;
---------------------------------------------------------
drop view if exists a2;
create view a2 as
select cust, prod as PRODUCT, min(quant) as Nj_min 
from sales 
where state='NJ' and year > 2000 
group by cust, prod;
---------------------------------------------------------
drop view if exists a3;
create view a3 as
select cust, prod as PRODUCT, min(quant) as CT_min 
from sales 
where state='CT' 
group by cust, prod;
---------------------------------------------------------
drop view if exists a4;
create view a4 as
select a1.cust,a1.PRODUCT,a1.NY_max,CONCAT(s.month,'/',s.day,'/' ,s.year) as MAX_DATE
from a1,sales as s
where a1.cust=s.cust
and a1.NY_max=s.quant;
---------------------------------------------------------
drop view if exists a5;
create view a5 as
select a2.cust,a2.PRODUCT,a2.NJ_min,CONCAT(s.month,'/',s.day,'/' ,s.year) as MIN_DATE_NJ
from a2,sales as s
where a2.cust=s.cust
and a2.NJ_min=s.quant;
---------------------------------------------------------
drop view if exists a6;
create view a6 as
select a3.cust,a3.PRODUCT,a3.CT_min,CONCAT(s.month,'/',s.day,'/' ,s.year) as MIN_DATE_CT
from a3,sales as s
where a3.cust=s.cust
and a3.CT_min=s.quant;
-----------------------------------------------------------
drop view if exists a7;
create view a7 as
select * from 
a4 natural full outer join a5;
-----------------------------------------------------------
select * from 
a7 natural full outer join a6
