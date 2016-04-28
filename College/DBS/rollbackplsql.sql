declare
begin
	savepoint none;
	update names set name = 'shiva' where name = 'shivam';
	if sql%found then
		dbms_output.put_line('Rollback to start.');
		rollback to savepoint none;
	end if;
end;
/