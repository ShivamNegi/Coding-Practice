declare
x number;
no number;
rev_no number;
begin
x := &x;
no := x;
rev_no := 0;

while round(x) != 0
	loop
	rev_no := rev_no * 10 + x mod 10;
	x := round(x / 10);
	end loop;

if 	no = rev_no then
	dbms_output.put_line('Palindrome Number.');
else
	dbms_output.put_line('Not Palindrome.')	;
end if;
end;
/	