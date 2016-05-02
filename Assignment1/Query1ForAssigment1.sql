drop view if exists v1;
create view v1 as
select cust , max(quant) as max_q ,min(quant) as min_q, avg(quant) from sales group by cust;
---------------------------------------------------------
drop view if exists v2;
create view v2 as
select v1.cust,v1.max_q,s.prod as max_prod,s.day as max_day,s.month as max_month,s.year as max_year,s.state as max_state
from v1,sales as s
where v1.cust=s.cust
and v1.max_q=s.quant;
---------------------------------------------------------
drop view if exists v3;
create view v3 as
select v1.cust,v1.min_q,s.prod as min_prod,s.day as min_day,s.month as min_month,s.year as min_year,s.state as min_st,v1.avg
from v1,sales as s
where v1.cust=s.cust
and v1.min_q=s.quant;
---------------------------------------------------------
select * 
from v2 natural join v3