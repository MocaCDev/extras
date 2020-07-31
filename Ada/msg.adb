with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure WriteMsg is
    msg: string(1..100);
    length_of_msg: Integer;
begin
    Put("Message to write: ");
    get_line(msg,length_of_msg);
    
    if length_of_msg > 0 and msg /= " " then
        Put(msg(1..length_of_msg));
    elsif msg = " " or length_of_msg < 1 then
        Put_Line("No message displayed");
    end if;
end WriteMsg;
