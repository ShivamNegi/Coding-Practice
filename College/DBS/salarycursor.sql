declare
cursor c1 is 
	with final(b_id) is
	(select branch_id, count(reg_no) from staff natural join client)
	select branch_id as beedi from staff where beedi = 
	(select branch_id, count(reg_no) from staff natural join client beedi = branch_id group by branch_id)

row c1%rowtype;	
begin
	for row in c1
		loop

		end loop;
end;
/