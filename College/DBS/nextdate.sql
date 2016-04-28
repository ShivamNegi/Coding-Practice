declare
given_date varchar2(20);
next_date date;
begin
	given_date := '&given_date';
	insert into tbl_next_date values(given_date, given_date);
end;
/	

