//Entry -> Memory ->  Sections

Entry(Reset_Handler)

Memory
{
  FLASH(rx) : ORIGIN = 0x08000000, Length = 512k
  RAM(rwx)  : ORIGIN = 0x20000000, Length = 128k
}

_estack = ORIGIN(RAM) + Length(RAM);

Sections
{
  
}