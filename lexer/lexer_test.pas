{
	Use this program to test your lexer
}
	
program lexer_test;

type
  int = integer;

Var
  i : integer;
  b : boolean;

function foo(x : integer) : i; forward;

procedure bar(x : int); forward;

begin
  if
  int := 2-1;
  i := int;
  i := integer;
  integer := 0;
  false := b;
  true := b and false;
  bar(int);
  bar(integer)
  test_string := "This is a string.\\";
end.
^
