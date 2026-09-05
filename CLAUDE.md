# Project Rules

## Environment
- Target: STM32F446RE, bare-metal only (no CubeMX/HAL in actual code files).

## Code
- Never modify or suggest CubeMX/HAL code in actual project files.
- Always write/edit register-level bare-metal code only.

## Explanations
- When explaining register code, always cover, in order:
  1. Which register (include RM0390 section number)
  2. Bit value calculation and why
  3. Actual address (base + offset)
- A "this is what CubeMX/HAL would generate" comparison is allowed for 
  understanding only — never apply it to actual files.
- Don't give the full answer immediately. Give a hint first, let me try, 
  then give feedback.