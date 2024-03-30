library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity demux_1x8 is
port(
	i:in std_logic;
	s:in std_logic_vector(2 downto 0);
	o:out std_logic_vector(7 downto 0)
);
end demux_1x8;

architecture behavioral of demux_1x8 is
begin
	o(0)<=i when s="000" else'0';
	o(1)<=i when s="001" else'0';
	o(2)<=i when s="010" else'0';
	o(3)<=i when s="011" else'0';
	o(4)<=i when s="100" else'0';
	o(5)<=i when s="101" else'0';
	o(6)<=i when s="110" else'0';
	o(7)<=i when s="111" else'0';
end behavioral;
