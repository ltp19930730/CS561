with cp as(select cust, prod ,sum(quant)
from sales
group by cust, prod),

--select * from cp
q1 as(
select cust, prod,sum(quant)
from sales
where month between 1 and 3
group by cust, prod),
q2 as(
select cust, prod,sum(quant)
from sales
where month between 4 and 6
group by cust, prod),
q3 as(
select cust, prod,sum(quant)
from sales
where month between 7 and 9
group by cust, prod),
q4 as(
select cust, prod,sum(quant)
from sales
where month between 10 and 12
group by cust, prod),

--select * from q4
summ as(
select cp.cust,cp.prod,cp.sum/3 as third, q1.sum as q1,q2.sum as q2,q3.sum as q3,q4.sum as q4
from cp 
left outer join q1 on cp.cust=q1.cust and cp.prod=q1.prod
left outer join q2 on cp.cust=q2.cust and cp.prod=q2.prod
left outer join q3 on cp.cust=q3.cust and cp.prod=q3.prod
left outer join q4 on cp.cust=q4.cust and cp.prod=q4.prod
),
summ2 as(
select cust,prod,third,
case when q1 is null then 0
when q1 is not null then q1 end q1,

case when q2 is null then 0 
when q2 is not null then q2 end q2,

case when q3 is null then 0
when q3 is not null then q3 end q3,

case when q4 is null then 0
when q4 is not null then q4 end q4
from summ
)

select cust, prod,
case 
when q1>=third then 'Q1' 
when q1<third and q1+q2>=third then 'Q2' 
when q1+q2<third and q1+q2+q3>= third then 'Q3' 
when q1+q2+q3<third then 'Q4' end ONE_Third_QUANT_PURCHASED_BY
from summ2
order by cust


