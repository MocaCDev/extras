with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure HelloWorld is
    N: Integer;
begin
    Put("Enter a number: ");
    Get(N);
    if N < 10 or N = 55 then
        if N = 55 then
            Put("Number N is");
            Put(N);
            New_Line;
        else
            Put("N is");
            Put(N);
            New_Line;
        end if;
    else
        Put(N);
        New_Line;
    end if;
end HelloWorld;
