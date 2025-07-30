# Car Wash and Maintenance Scheduling System

This C program manages reservations for car washes (`l`) and maintenance services (`m`) using a doubly-linked list with pre-reservation capabilities. The system handles scheduling, cancellation, and time conflict resolution while adhering to business hour constraints.

## Features
- **Reservation Management**: Schedule washes/maintenance with time validation
- **Conflict Handling**: Automatic pre-reservations for occupied slots
- **Persistent Storage**: Save/load reservations from `data.txt`
- **Time Calculations**: Date/minute conversions with calendar awareness
- **Client Operations**: List reservations by client name
- **Service Completion**: Remove completed services from schedule

## File Structure
├── data.txt # Reservation database\
├── lista.c # Linked list implementation\
├── lista.h # List function declarations\
├── main.c # Command-line interface\
├── README.md # This file\
└── struct.h # Data structure definitions


## Requirements
- C compiler (GCC recommended)
- Standard C libraries (stdio.h, stdlib.h, string.h)

## Compilation & Execution

gcc -o scheduler main.c lista.c
./scheduler

## Commands

-RESERVAR:	Make new reservation	
  -Name/type DD/MM HH:MM (e.g., Diogo/l 30/6 17:30)
-CANCELAR: Cancel reservation	
  -DD/MM HH:MM
-LISTAR: List all reservations	
  -(no arguments)
-LISTAR_CLIENTE:	List reservations for specific client	
  -Name
-CONCLUIR:	Complete next service 
  -(no arguments)
-CARREGAR:	Load reservations from file	
  -(no arguments)
-GUARDAR:	Save reservations to file	
  -(no arguments)
-SAIR:	Exit program	 
  -(no arguments)

## Business Rules
-Operating Hours: 8:00 - 18:00

-Time Slots: Only :00 and :30 minutes allowed

-Maintenance Restrictions:

  -Cannot be scheduled at 17:30

  -Requires 60 minutes duration

-Wash Duration: Requires 30 minutes

-Conflict Handling:

  -Automatically creates pre-reservations for occupied slots

  -Pre-reservations are stored in reverse chronological order

## Technical Notes
-Uses doubly-linked list with main reservations in next pointers

-Stores pre-reservations in prev pointers (reverse chronological order)

-Handles date/minute conversions considering month lengths

-Validates all input times against business rules

## Known Limitations
-No leap year handling

-Pre-reservations don't auto-promote on cancellation

-Year not considered in date calculations

-No input validation for month values (1-12)

## Requirements
- C compiler (GCC recommended)
- Standard C libraries (stdio.h, stdlib.h, string.h)

## Compilation & Execution
1. **Compile the program**:
 make

2. This will create an executable named ppp_project.

3. Run the program in a terminal:
./ppp_project

4. At runtime:

The program loads existing reservations from data.txt (if available)

You'll see the prompt: Indique a operação:

Enter commands like RESERVAR, LISTAR, etc. 

## Example Usage

### After compiling:
./ppp_project

Indique a operação: 
RESERVAR
Introduza o nome, tipo e data: Diogo/l 30/6 17:30

Indique a operação: 
LISTAR
Nome: Diogo - Tipo: l - Data: 30/6 17:30

Indique a operação: 
GUARDAR
Marcações a carregar:
30/6 17:30
Dados carregados.

Indique a operação: 
SAIR
