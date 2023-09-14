select sum(money)
from (
select price*p_num money
from
(select *
from Product_info
where pro_name like '%办公椅%') t1
join Purchase t2
on t1.pro_no=t2.pro_no ) t3
