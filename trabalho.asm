# Uma tabela Hash implementada em Assembly MIPS para a matéria de Organização de Computadores Digitais
# Membros: Bruno Coelho, Gabriel Cruz, Gabriel Cyrillo, Alex Sander

.data
.align 0	
	strInicio: .asciiz "Tabela Hash de inteiros implementada em MIPS Assembly.\n"
	strOpcao: .asciiz  "Digite 1 para a inserção de um número, 2 para remoção, 3 para busca, 4 para a visualazição da tabela e 5 para sair do programa.\n"
	strInvalidInput: .asciiz "Opção não válida digitada, favor digitar um inteiro de 1 a 5 conforme as opções fornecidas.\n"
	strExit:.asciiz "Finalizando programa\n"
	
	
.text
.globl main

main:	
	li $v0, 4	# imprime string
	la $a0, strInicio
	
	syscall		
	
menu:
	li $v0, 4	# imprime string
	la $a0, strOpcao
	syscall
	li $v0, 5	# ler inteiro
	syscall 	# numero digitado em $a0
	move $s1, $v0	# guardando o numero em s1
	
	beq $s1, +1, insercao
	beq $s1, +2, remocao
	beq $s1, +3, busca
	beq $s1, +4 impressao
	beq $s1, +5, endProgram
	j invalidInput		# se chegar aqui, o usuario digitou algum número não valido
	
invalidInput:
	li $v0, 4	# imprime string
	la $a0, strInvalidInput
	syscall
	j menu		# voltamos ao menu


# Funções Placeholders, depois coloquem as suas partes aqui.
insercao:
	j endProgram
	
remocao:
	j endProgram
	
busca:
	j endProgram
	
impressao:
	j endProgram
	
endProgram:
	li $v0, 4	# imprime string
	la $a0, strExit
	syscall
	li $v0, 10	# exit
	syscall