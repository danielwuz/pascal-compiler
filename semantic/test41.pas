{ 
	This program is lexical and parsing error-free. 
	It has multi-declaration error.
}

program errormulti;
type
	s = string;
	in = integer;
var
	z : s;
	m : in;
	z : in;  {error: multiple declaration}

begin
	z := 5;
	m := 7;	
end.