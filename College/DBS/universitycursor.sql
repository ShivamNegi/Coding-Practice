declare
	cursor c1 is 
		select * from student order by tot_cred asc;
	row c1%rowtype;
begin	
	for row in c1
	loop	
		dbms_output.put_line('id:' || row.id || ', name:' || row.name);
		exit when c1%rowcount = 10;
	end loop;		
end;
/