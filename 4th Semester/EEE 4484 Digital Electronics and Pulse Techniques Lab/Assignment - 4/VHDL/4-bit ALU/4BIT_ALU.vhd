library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
 
entity ALU_4bit is
port (
	a : in signed(3 downto 0);
	b : in signed(3 downto 0);
	s : in STD_LOGIC_VECTOR (1 downto 0);
	o : out signed(3 downto 0));
end ALU_4bit;
 
architecture behavioral of ALU_4bit is
begin
process(a, b, s)
	begin
	case s is
 		when "00" => o <= a + b;
 		when "01" => o <= a - b;
 		when "10" => o <= a AND b;
 		when "11" => o <= a OR b;
 		when others => NULL;
	end case;
end process;

end behavioral;