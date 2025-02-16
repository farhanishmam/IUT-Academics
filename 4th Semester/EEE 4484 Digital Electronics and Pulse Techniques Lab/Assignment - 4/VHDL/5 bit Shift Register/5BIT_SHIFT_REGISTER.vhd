library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity shift_reg_5bit is
port(
	clk : in std_logic;
	D: in std_logic_vector(3 downto 0);
	Q: out std_logic_vector(3 downto 0)
);
end shift_reg_5bit;
 
architecture behavioral of shift_reg_5bit is
 
begin
process (clk,D)
	begin
	if (clk'event and clk='1') then Q <= D;
	end if;
end process;

end behavioral;